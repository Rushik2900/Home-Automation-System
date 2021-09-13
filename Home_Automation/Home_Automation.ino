#include <ESP8266WiFi.h>
#include<Servo.h>
#include<DHT.h>
Servo myservo;

int DHTPIN = 16;
#define DHTTYPE DHT11                                        
DHT dht(DHTPIN, DHTTYPE);
#define ON LOW
#define OFF HIGH

const char* ssid = "Rushik";
const char* password = "Rushik@29";
 
int RELAY1 = 2;  //D1 on ESP Board
int RELAY2 = 0;  //D2 on ESP Board
int RELAY3 = 4;  //D3 on ESP Board
int RELAY4 = 5;  //D4 on ESP Board
int RELAY5 = 15; //D5 on ESP Board
int RELAY6 = 12; //D6 on ESP Board
int RELAY7 = 14; //D7 on ESP Board
int RELAY8 = 13; //D8 on ESP Board

int value1 = OFF, value2 = OFF, value3 = OFF, value4 = OFF;
int value5 = OFF, value6 = OFF, value7 = OFF, value8 = OFF;
int value9 = OFF;
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
//  myservo.attach(1);
  pinMode(RELAY1, OUTPUT); digitalWrite(RELAY1, HIGH);
  pinMode(RELAY2, OUTPUT); digitalWrite(RELAY2, HIGH);
  pinMode(RELAY3, OUTPUT); digitalWrite(RELAY3, HIGH);
  pinMode(RELAY4, OUTPUT); digitalWrite(RELAY4, HIGH);
  pinMode(RELAY5, OUTPUT); digitalWrite(RELAY5, HIGH);
  pinMode(RELAY6, OUTPUT); digitalWrite(RELAY6, HIGH);
  pinMode(RELAY7, OUTPUT); digitalWrite(RELAY7, HIGH);
  pinMode(RELAY8, OUTPUT); digitalWrite(RELAY8, HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting wifi ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
 
  // Start the server
  server.begin();
  Serial.println("Starting Server");
 
  // Print the IP address
  Serial.print("Use the following URL to connect to ESP8266 : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {

  // Check if a client has connected
  int pos;
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
         
// Set LED according to the request
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<font color = lightblue>");
  client.println("<font size = 24>");
  client.println("<center>");
  client.print("Control 8 Relay Via Wifi");
  client.println("</font>");
  client.println("<br><br>");
 
 // Return the response RELAY1
  client.print("RELAY1 in condition : ");
  // Control LED 1
  if (request.indexOf("/RELAY1=ON") != -1)  {
    digitalWrite(RELAY1, ON);
    value1 = ON;}
  if (request.indexOf("/RELAY1=OFF") != -1)  {
    digitalWrite(RELAY1, OFF);
    value1 = OFF;}
     if(value1==ON){client.print("ON");}
     if(value1==OFF){client.print("OFF");}  
  client.println("<br><br>");
  client.println("<a href=\"/RELAY1=ON\"\"><button>RELAY1 ON </button></a>");
  client.println("<a href=\"/RELAY1=OFF\"\"><button>RELAY1 OFF </button></a><br />");  
  client.println("</html>");


 // Return the response RELAY2
 client.println("<br><br>");
 client.print("RELAY2 in condition : ");
  // Control LED 2
  if (request.indexOf("/RELAY2=ON") != -1)  {
    digitalWrite(RELAY2, ON);
    value2 = ON;}
  if (request.indexOf("/RELAY2=OFF") != -1)  {
    digitalWrite(RELAY2, OFF);
    value2 = OFF;}
    if(value2==ON){client.print("ON");}
    if(value2==OFF){client.print("OFF");}  
  client.println("<br><br>");
  client.println("<a href=\"/RELAY2=ON\"\"><button>RELAY2 ON </button></a>");
  client.println("<a href=\"/RELAY2=OFF\"\"><button>RELAY2 OFF </button></a><br />");  
  client.println("</html>");

 
  // Return the response RELAY3
  client.println("<br><br>");
  client.print("RELAY3 in condition : ");
  // Control LED 3
  if (request.indexOf("/RELAY3=ON") != -1)  {
    digitalWrite(RELAY3, ON);
    value3 = ON;}
  if (request.indexOf("/RELAY3=OFF") != -1)  {
    digitalWrite(RELAY3, OFF);
    value3 = OFF;}
    if(value3==ON){client.print("ON");}
    if(value3==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY3=ON\"\"><button>RELAY3 ON </button></a>");
  client.println("<a href=\"/RELAY3=OFF\"\"><button>RELAY3 OFF </button></a><br />");  
  client.println("</html>");

 
  // Return the response RELAY4
  client.println("<br><br>");
  client.print("RELAY4 in condition : ");
  // Control LED 4
  if (request.indexOf("/RELAY4=ON") != -1)  {
    digitalWrite(RELAY4, ON);
    value4 = ON;}
  if (request.indexOf("/RELAY4=OFF") != -1)  {
    digitalWrite(RELAY4, OFF);
    value4 = OFF;}
    if(value4==ON){client.print("ON");}
    if(value4==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY4=ON\"\"><button>RELAY4 ON </button></a>");
  client.println("<a href=\"/RELAY4=OFF\"\"><button>RELAY4 OFF </button></a><br />");  
  client.println("</html>");


  // Return the response RELAY5
  client.println("<br><br>");
  client.print("RELAY5 in condition : ");
  if (request.indexOf("/RELAY5=ON") != -1)  {
    digitalWrite(RELAY5, ON);
    value5 = ON;}
  if (request.indexOf("/RELAY5=OFF") != -1)  {
    digitalWrite(RELAY5, OFF);
    value5 = OFF;}
    if(value5==ON){client.print("ON");}
    if(value5==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY5=ON\"\"><button>RELAY5 ON </button></a>");
  client.println("<a href=\"/RELAY5=OFF\"\"><button>RELAY5 OFF </button></a><br />");  
  client.println("</html>");
 

  // Return the response RELAY6
  client.println("<br><br>");
  client.print("RELAY6 in condition : ");
  if (request.indexOf("/RELAY6=ON") != -1)  {
    digitalWrite(RELAY6, ON);
    value6 = ON;}
  if (request.indexOf("/RELAY6=OFF") != -1)  {
    digitalWrite(RELAY6, OFF);
    value6 = OFF;}
    if(value6==ON){client.print("ON");}
    if(value6==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY6=ON\"\"><button>RELAY6 ON </button></a>");
  client.println("<a href=\"/RELAY6=OFF\"\"><button>RELAY6 OFF </button></a><br />");  
  client.println("</html>");
 

  // Return the response RELAY7
  client.println("<br><br>");
  client.print("RELAY7 in condition : ");
  if (request.indexOf("/RELAY7=ON") != -1)  {
    digitalWrite(RELAY7, ON);
    value7 = ON;}
  if (request.indexOf("/RELAY7=OFF") != -1)  {
    digitalWrite(RELAY7, OFF);
    value7 = OFF;}
    if(value7==ON){client.print("ON");}
    if(value7==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY7=ON\"\"><button>RELAY7 ON </button></a>");
  client.println("<a href=\"/RELAY7=OFF\"\"><button>RELAY7 OFF </button></a><br />");  
  client.println("</html>");
 

  // Return the response RELAY8
  client.println("<br><br>");
  client.print("RELAY8 in condition : ");
  if (request.indexOf("/RELAY8=ON") != -1)  {
    digitalWrite(RELAY8, ON);
    value8 = ON;}
  if (request.indexOf("/RELAY8=OFF") != -1)  {
    digitalWrite(RELAY8, OFF);
    value8 = OFF;}
    if(value8==ON){client.print("ON");}
    if(value8==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/RELAY8=ON\"\"><button>RELAY8 ON </button></a>");
  client.println("<a href=\"/RELAY8=OFF\"\"><button>RELAY8 OFF </button></a><br />");  
  client.println("</html>");


  // Return the response GARAGE
  client.println("<br><br>");
  client.print("GARAGE : ");
  if (request.indexOf("/SERVO=ON") != -1)  {
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);  
    value9 = ON;} }
    if (request.indexOf("/SERVO=OFF") != -1)  {
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    value9 = OFF;}
    }
    if(value9==ON){client.print("ON");}
    if(value9==OFF){client.print("OFF");}
  client.println("<br><br>");
  client.println("<a href=\"/SERVO=ON\"\"><button>SERVO ON </button></a>");
  client.println("<a href=\"/SERVO=OFF\"\"><button>SERVO OFF </button></a><br />");  
  client.println("</html>");

  float h = dht.readHumidity();                                 
  float t = dht.readTemperature();  
  if (isnan(h) || isnan(t))                                    
  {                                   
    client.println("Failed to read from DHT sensor!");
  } 
  else
  {
    client.println("<br /> Humidity : ");
    client.println(dht.readHumidity(), 1);
    client.println("<br /> Temparature :");
    client.println(dht.readTemperature(), 1);
    delay(1);
  }
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
