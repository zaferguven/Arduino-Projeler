#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
// Define the digital inputs
#define jB1 1  // Joystick button 1
#define jB2 0  // Joystick button 2
#define t1 7   // Toggle switch 1
#define t2 4   // Toggle switch 1
#define b1 8   // Button 1
#define b2 9   // Button 2
#define b3 2   // Button 3
#define b4 3   // Button 4
RF24 radio(3, 2);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  byte j1PotY;
  byte j1PotX;
  byte j2PotY;
  byte j2PotX;
  byte button1;
};
Data_Package data; //Create a variable with the above structure

void setup() {
  Serial.begin(9600);
  // Define the radio communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  // Set initial default values
  data.j1PotX = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 127;
  pinMode(b1, INPUT_PULLUP);
  data.button1 = 1;
}

void loop() {
  // Read all analog inputs and map them to one Byte value
  data.j2PotX = map(analogRead(A1), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.j1PotX = map(analogRead(A0), 0, 1023, 0, 255);
  data.button1 = digitalRead(b1);
  radio.write(&data, sizeof(Data_Package));
}
