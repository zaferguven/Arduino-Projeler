#include <ESP8266WiFi.h>

const char* ssid = "wifi adı";
const char* password = "password";

WiFiServer server(80);

String header;
String r1State = "OFF";
String r2State = "OFF";
String r3State = "OFF";
String r4State = "OFF";
String r5State = "OFF";
String r6State = "OFF";
const int r1 = D0;
const int r2 = D1;
const int r3 = D2;
const int r4 = D3;
const int r5 = D4;
const int r6 = D5;

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(r3, LOW);
  digitalWrite(r4, LOW);
  digitalWrite(r5, LOW);
  digitalWrite(r6, LOW);
  Serial.println("AT+CWMODE=1");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP Adresi: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available(); 

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();         
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            if (header.indexOf("GET /r1/off") >= 0) {
              Serial.println("r1 off");
              r1State = "OFF";
              digitalWrite(r1, LOW);
            }
            else if (header.indexOf("GET /r1/on") >= 0) {
              Serial.println("r1 on");
              r1State = "ON";
              digitalWrite(r1, HIGH);
            }
            else if (header.indexOf("GET /r2/off") >= 0) {
              Serial.println("r2 off");
              r2State = "OFF";
              digitalWrite(r2, LOW);
            }
            else if (header.indexOf("GET /r2/on") >= 0) {
              Serial.println("r2 on");
              r2State = "ON";
              digitalWrite(r2, HIGH);
            }
            else if (header.indexOf("GET /r3/off") >= 0) {
              Serial.println("r3 off");
              r3State = "OFF";
              digitalWrite(r3, LOW);
            }
            else if (header.indexOf("GET /r3/on") >= 0) {
              Serial.println("r3 on");
              r3State = "ON";
              digitalWrite(r3, HIGH);
            }
            else if (header.indexOf("GET /r4/off") >= 0) {
              Serial.println("r4 off");
              r4State = "OFF";
              digitalWrite(r4, LOW);
            }
            else if (header.indexOf("GET /r4/on") >= 0) {
              Serial.println("r4 on");
              r4State = "ON";
              digitalWrite(r4, HIGH);
            }
            else if (header.indexOf("GET /r5/off") >= 0) {
              Serial.println("r5 off");
              r5State = "OFF";
              digitalWrite(r5, LOW);
            }
            else if (header.indexOf("GET /r5/on") >= 0) {
              Serial.println("r5 on");
              r5State = "ON";
              digitalWrite(r5, HIGH);
            }
            else if (header.indexOf("GET /r6/off") >= 0) {
              Serial.println("r6 off");
              r6State = "OFF";
              digitalWrite(r6, LOW);
            }
            else if (header.indexOf("GET /r6/on") >= 0) {
              Serial.println("r6 on");
              r6State = "ON";
              digitalWrite(r6, HIGH);
            }
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            client.println("<title>ZAFER GUVEN - WIFI KONTROL SISTEMI</title>");
            client.println("<body><h1>WIFI KONTROL SISTEMI</h1>");
            client.println("<br><h3>B1 DURUM = " + r1State + "</h3>");
            if (r1State=="OFF") {
              client.println("<p><a href=\"/r1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>B2 DURUM = " + r2State + "</h3>");
            if (r2State=="OFF") {
              client.println("<p><a href=\"/r2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>B3 DURUM = " + r3State + "</h3>");
            if (r3State=="OFF") {
              client.println("<p><a href=\"/r3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>B4 DURUM = " + r4State + "</h3>");
            if (r4State=="OFF") {
              client.println("<p><a href=\"/r4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>B5 DURUM = " + r5State + "</h3>");
            if (r5State=="OFF") {
              client.println("<p><a href=\"/r5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>B6 DURUM = " + r6State + "</h3>");
            if (r6State=="OFF") {
              client.println("<p><a href=\"/r6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/r6/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("<br><h3>&copy; 2022 - ZAFER GUVEN - Kisisel Web Site - www.zaferguven.com</h3>");
            client.println("</body></html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
