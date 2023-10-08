/*                              PROJECT - 2
In the following code, to develop a automated  house system which can be controlled from the mobile or 
computer devices woth the help of the cloud.
To control all the parameters at the same place we can make an app or create a website,
which can used for maintaining the output and input of the appliances with the help of the NodeMCU 
The app's functions like turning on or turning off of the appliance is connected to the server created for control of the pins which changes the input of them
in the micro controller. 
                                                                    Vikas S

*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

const char* ssid = "Redmi Y1";
const char* password = "abviki14";

ESP8266WebServer server(80);
String website="";
int sensor=12;
int led0=13;
int led1=4;
int led2=5;
int sensor_output=16;


void setup(void) {
 website +="<meta http-equiv='refresh' content='3'><title>ESP8266</title>\n";
 website +="<style>body{background-color:cadetblue;font-family: 'Tangerine','Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;color:black;}</style>\n";
 website +="<h2 dir=\'rt1\' style='text align:left; '><img src='https://www.safewise.com/app/uploads/smart-home-1.jpg' style='float:left;height:350px;width: 900px; border: 2px orange dashed;'></h2>";
 website +="<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>\n";
 website += "<a><button onclick='myFunction()'>HOME</button></a>";
 website += "<h1>ESP8266</h1><p>LED #1<a href='socket1on'><button>ON</button></a>&nbsp;<a href='socket1off'><button>OFF</button></a></p>\n";
 website +="<p>LED #2<a href='socket2on'><button>ON</button></a>&nbsp;<a href='socket2off'><button>OFF</button></a></p>\n";
 website +="<p><h2>Condition of the Sensor</h2></p>\n";

 pinMode(led0,OUTPUT);
 digitalWrite(led0,LOW);
 pinMode(led1,OUTPUT);
 digitalWrite(led1,LOW);
 pinMode(led2,OUTPUT);
 digitalWrite(led2,LOW);

 
 Serial.begin(115200);
 WiFi.begin(ssid, password);
Serial.println();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(led0,HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266",WiFi.localIP())){
  Serial.println("MDNS responder started");
}
server.on("/",[](){
  server.send(200,"text/html",website);
});

server.on("/socket1on",[](){
  server.send(200,"text/html",website);
  digitalWrite(led1,HIGH);
});
server.on("/socket1off",[](){
  server.send(200,"text/html",website);
  digitalWrite(led1,LOW);
});
server.on("/socket2on",[](){
  server.send(200,"text/html",website);
  digitalWrite(led2,HIGH);
});
server.on("/socket2off",[](){
  server.send(200,"text/html",website);
  digitalWrite(led2,LOW);
});

server.begin();
Serial.println("HTTP server started"); 
 }

 void loop(void){
  server.handleClient();
  String sent ="<p>Flame detected!!!!...</p>";
  if (WiFi.status() !=WL_CONNECTED){
    digitalWrite(led0,LOW);
    Serial.println("");
    Serial.println("WiFi is disconnected");
    Serial.println("");
    Serial.print("Reconnecting");
    Serial.println("");
   
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    digitalWrite(led0,HIGH);
  }

  if(digitalRead(sensor_output)==LOW){
    Serial.print("Flame Detected");
    Serial.println("");
    website +=sent;
    digitalWrite(sensor_output,HIGH);
    delay(300);
  }
 //if sensor is not present
 else{
  digitalWrite(sensor_output,LOW);
 }
 }
