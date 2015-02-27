// Wunderground.ino
#include <LM35.h>
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include "Time.h"

EthernetClient client;
byte mac[]={
	0x90, 0xA2, 0xDA, 0x0F, 0x9D, 0x80 };
EthernetUDP udp;
void setup() {
	Ethernet.begin(mac);
	Serial.begin(9600);
	setTime(ntpUnixTime(udp));
}

void loop() {
	/*client.connect("http://weatherstation.wunderground.com");
	String requestUrl="http://weatherstation.wunderground.com/weatherstation/updateweatherstation.php?action=updateraw&ID=IEMILIAR166&PASSWORD=eu@123tampieri&dateutc="+*/
	Serial.println(dateUtc());
}
/*
 * © Francesco Potortì 2013 - GPLv3 - Revision: 1.13
 *
 * Send an NTP packet and wait for the response, return the Unix time
 *
 * To lower the memory footprint, no buffers are allocated for sending
 * and receiving the NTP packets.  Four bytes of memory are allocated
 * for transmision, the rest is random garbage collected from the data
 * memory segment, and the received packet is read one byte at a time.
 * The Unix time is returned, that is, seconds from 1970-01-01T00:00.
 */
unsigned long inline ntpUnixTime (UDP &udp)
{
	static int udpInited = udp.begin(123); // open socket on arbitrary port

	const char timeServer[] = "pool.ntp.org";  // NTP server

	// Only the first four bytes of an outgoing NTP packet need to be set
	// appropriately, the rest can be whatever.
	const long ntpFirstFourBytes = 0xEC0600E3; // NTP request header

	// Fail if WiFiUdp.begin() could not init a socket
	if (! udpInited)
	return 0;

	// Clear received data from possible stray received packets
	udp.flush();

	// Send an NTP request
	if (! (udp.beginPacket(timeServer, 123) // 123 is the NTP port
	&& udp.write((byte *)&ntpFirstFourBytes, 48) == 48
	&& udp.endPacket()))
	return 0;				// sending request failed

	// Wait for response; check every pollIntv ms up to maxPoll times
	const int pollIntv = 150;		// poll every this many ms
	const byte maxPoll = 15;		// poll up to this many times
	int pktLen;				// received packet length
	for (byte i=0; i<maxPoll; i++) {
	if ((pktLen = udp.parsePacket()) == 48)
		break;
	delay(pollIntv);
	}
	if (pktLen != 48)
	return 0;				// no correct packet received

	// Read and discard the first useless bytes
	// Set useless to 32 for speed; set to 40 for accuracy.
	const byte useless = 40;
	for (byte i = 0; i < useless; ++i)
	udp.read();

	// Read the integer part of sending time
	unsigned long time = udp.read();	// NTP time
	for (byte i = 1; i < 4; i++)
	time = time << 8 | udp.read();

	// Round to the nearest second if we want accuracy
	// The fractionary part is the next byte divided by 256: if it is
	// greater than 500ms we round to the next second; we also account
	// for an assumed network delay of 50ms, and (0.5-0.05)*256=115;
	// additionally, we account for how much we delayed reading the packet
	// since its arrival, which we assume on average to be pollIntv/2.
	time += (udp.read() > 115 - pollIntv/8);

	// Discard the rest of the packet
	udp.flush();

	return time - 2208988800ul;		// convert NTP time to Unix time
}
void digitalClockDisplay(){
	// digital clock display of the time
	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(" ");
	Serial.print(day());
	Serial.print(" ");
	Serial.print(month());
	Serial.print(" ");
	Serial.print(year());
	Serial.println();
}
void printDigits(int digits){
	// utility function for digital clock display: prints preceding colon and leading 0
	Serial.print(":");
	if(digits < 10)
	Serial.print('0');
	Serial.print(digits);
}
String dateUtc(){
	String date;
	char ora[2];
	char minuto[2];
	char secondo[2];
	char mese[2];
	char giorno[2];
	itoa(month(), mese, 10);
	itoa(day(), giorno, 10);
	itoa(hour(), ora, 10);
	itoa(minute(), minuto, 10);
	itoa(second(), secondo, 10);
	/*if(month()<=9){
		mese='0'+mese;
	}
	if(day()<=9){
		giorno='0'+giorno;
	}
	if(hour()<=9){
		ora='0'+ora;
	}
	if(minute()<=9){
		minuto='0'+minuto;
	}
	if(second()<=9){
		secondo='0'+secondo;
	}*/
	char anno[4];
	itoa(year(), anno, 10);
	date=anno+'-'+mese+'-'+giorno+' '+ora+':'+minuto+':'+secondo;
	return date;
}