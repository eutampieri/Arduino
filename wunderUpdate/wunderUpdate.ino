/*
 * Time_NTP sketch
 * Example showing time sync to NTP time source
 * This sketch uses the Time library
 * and the Arduino Ethernet library
 */
#include<LM35.h>
#include <Time.h>
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUDP.h>
EthernetClient client;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x9D, 0x80 };

unsigned int localPort = 8888;      // local port to listen for UDP packets

IPAddress timeServer(193,204,114,232); // time.nist.gov NTP server

const int NTP_PACKET_SIZE= 48; // NTP time stamp is in first 48 bytes of message
byte packetBuffer[ NTP_PACKET_SIZE]; // buffer to hold incoming/outgoing packets

time_t prevDisplay = 0;    // when the digital clock was displayed

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac);
  Udp.begin(localPort);
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  while(timeStatus()== timeNotSet)
     ; // wait until the time is set by the sync provider
  client.connect("weatherstation.wunderground.com",80);
}

void loop()
{
 float tempF=readF(A0);
 float oldtempF=0;
 if(tempF>oldTempF+0.3||tempF<oldTempF-0.3){
  String getURL='GET /weatherstation/updateweatherstation.php?action=updateraw&ID=IEMILIAR166&PASSWORD=GAx-Wb2-yzF-saq&dateutc="%d"&tempf="%f',now(),tempF
   client.println(getUrl);
   oldtempF=tempF;
 }
}
/*-------- NTP code ----------*/

unsigned long getNtpTime()
{
  sendNTPpacket(timeServer); // send an NTP packet to a time server
  delay(1000);
  if ( Udp.parsePacket() ) { 
     Udp.read(packetBuffer,NTP_PACKET_SIZE);  // read packet into buffer

     //the timestamp starts at byte 40, convert four bytes into a long integer
     unsigned long hi = word(packetBuffer[40], packetBuffer[41]);
     unsigned long low = word(packetBuffer[42], packetBuffer[43]);
     // this is NTP time (seconds since Jan 1 1900
     unsigned long secsSince1900 = hi << 16 | low;  
     // Unix time starts on Jan 1 1970
     const unsigned long seventyYears = 2208988800UL;     
     unsigned long epoch = secsSince1900 - seventyYears;  // subtract 70 years
     return epoch;
  }
  return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
unsigned long sendNTPpacket(IPAddress address)
{
  memset(packetBuffer, 0, NTP_PACKET_SIZE);  // set all bytes in the buffer to 0

  // Initialize values needed to form NTP request
  packetBuffer[0] = B11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum
  packetBuffer[2] = 6;     // Max Interval between messages in seconds
  packetBuffer[3] = 0xEC;  // Clock Precision
  // bytes 4 - 11 are for Root Delay and Dispersion and were set to 0 by memset
  packetBuffer[12]  = 49;  // four-byte reference ID identifying
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // send the packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer,NTP_PACKET_SIZE);
  Udp.endPacket();
}
