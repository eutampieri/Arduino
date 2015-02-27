/*
 * WebServerMultiPageHTML
 * Arduino 1.0 version
 * Display analog and digital pin values using HTML formatting
 */
#include <LM35.h>
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>

byte mac[]={0x90, 0xA2, 0xDA, 0x0F, 0x9D, 0x80 };
byte ip[] =  { 192,168,1,177 };
const String firstPart="<html><head>  <meta charset='utf-8''>  <title>ET Software</title>  <meta name='viewport' content='width=device-width, initial-scale=1'><link rel='stylesheet' href='add2home.css'><script type='application/javascript' src='http://etsoftware.bl.ee/m/add2home.js'></script><link rel='apple-touch-icon' href='http://etsoftware.bl.ee/m/touchlogo.png' />  <meta name='apple-mobile-web-app-capable' content='yes'>  <meta name='apple-mobile-web-app-status-bar-style' content='black'>  <link href='http://etsoftware.bl.ee/m/css/codiqa.ext.min.css' rel='stylesheet'>  <link href='http://etsoftware.bl.ee/m/css/jquery.mobile-1.3.1.min.css' rel='stylesheet'>  <script src='http://etsoftware.bl.ee/m/js/jquery-1.9.1.min.js'></script>  <script src='http://etsoftware.bl.ee/m/js/jquery.mobile-1.3.1.min.js'></script>  <script src='http://etsoftware.bl.ee/m/js/codiqa.ext.min.js'></script>  <script src='http://etsoftware.bl.ee/m/js/et-software.js'></script></head><body><div data-role='page' data-control-title='Home' id='home'>    <div data-theme='b' data-role='header'>        <h1>            TermoLight</h1><h5>Powered by Arduino</h5></div><div data-role='content'><center><img src='h'http://arduino.cc/logo.png' alt='image' tyle='position: absolute; top: 50%; left: 50%; margin-left: -16px; margin-top: -18px'></center><br><br><br><br><center><div data-controltype='image'><img src='http://i.imgur.com/VOjm1Hp.png' alt='image' ></div><div data-controltype='textblock'><b>";
const String secondPart="</b></div><hr><div><img src='http://i.imgur.com/Uea2t1u.png' alt='image'></div><div data-controltype='textblock'><b>";
const String thirdPart="</b></center></div><div data-theme='b' data-role='footer' data-position='fixed'><h3>By Eugenio Tampieri</h3></div></div></body></html>";

// Buffer must be big enough to hold requested page names and terminating null
const int MAX_PAGE_NAME_LEN = 8+1;  // max characters in a page name + null
char buffer[MAX_PAGE_NAME_LEN]; 

EthernetServer server(80);
EthernetClient client;

void setup()
{
  Serial.begin(9600);  
  
  Ethernet.begin(mac);
  server.begin();
  pinMode(13,OUTPUT);
  for(int i=0; i < 3; i++)
  {
     digitalWrite(13,HIGH);
     delay(500);
     digitalWrite(13,LOW);
     delay(500);
  }
}

void loop()
{
  client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        if( client.find("GET ") ) {
          // look for the page name
          memset(buffer,0, sizeof(buffer)); // clear the buffer
            showPage();
        break;
      }
    }
    // give the web browser time to receive the data
    delay(1);
    client.stop();
  }
}
}

void showPage(){
  sendHeader();
  client.println(firstPart);
  client.println(readC(A0));
  client.println(secondPart);
  client.println(thirdPart);
}

void sendHeader()
{
  // send a standard http response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
}  
