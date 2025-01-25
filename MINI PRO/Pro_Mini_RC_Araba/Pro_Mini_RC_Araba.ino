#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define led 5    // CH2
#define korna 7  // CH4
#define far 8    // CH5
#define stop12 9 // CH6

RF24 radio(3, 2); // nRF24L01 (CE, CSN)
const byte address[6] = "00001";
unsigned long lastReceiveTime = 0;
unsigned long currentTime = 0;

Servo throttle;
Servo rudderServo;
Servo elevatorServo;
Servo aileron1Servo;
Servo aileron2Servo;

int throttleValue, rudderValue, elevatorValue, aileron1Value, aileron2Value, travelAdjust;
struct Data_Package {
  byte j1PotX;
  byte j1PotY;
  byte j1Button;
  byte j2PotX;
  byte j2PotY;
  byte j2Button;
  byte pot1;
  byte pot2;
  byte tSwitch1;
  byte tSwitch2;
  byte button1;
  byte button2;
  byte button3;
  byte button4;
};
Data_Package data;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  resetData();
  throttle.attach(10);     // CH9
  elevatorServo.attach(4); // CH1
  pinMode(led, OUTPUT);    // CH2
  pinMode(korna, OUTPUT);  // CH4
  pinMode(far, OUTPUT);    // CH5
  pinMode(stop12, OUTPUT); // CH6
}

void loop() {
  currentTime = millis();
  if ( currentTime - lastReceiveTime > 1000 ) {
    resetData();
  }
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package));
    lastReceiveTime = millis();
  }

  // ESC Fırçasız Motor Kontrolü
  throttleValue = constrain(data.j1PotY, 130, 255);
  throttleValue = map(throttleValue, 130, 255, 1000, 2000);
  throttle.writeMicroseconds(throttleValue);
  
  // Servo Motor Kontrolü
  elevatorValue = map(data.j2PotX, 30, 255, (0 - travelAdjust), (100 + travelAdjust));
  elevatorServo.write(elevatorValue);

  // Batarya Kontrol Led i
  int sensorValue = analogRead(A3);
  float voltage = sensorValue * (5.00 / 1023.00) * 3;
  if (voltage < 11) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }

  // Far Kontrol
  if (data.tSwitch2 < 1 ) {
    digitalWrite(far, HIGH);
    digitalWrite(stop12, HIGH);
  }
  else {
    digitalWrite(far, LOW);
    digitalWrite(stop12, LOW);
  }

  // Korna Kontrol
  if (data.button3 < 1 ) {
    digitalWrite(korna, HIGH);
  }
  else {
    digitalWrite(korna, LOW);
  }
}

void resetData() {
  data.j1PotX = 127;
  data.j1PotY = 130;
  data.j2PotX = 127;
  data.j2PotY = 127;
  data.j1Button = 1;
  data.j2Button = 1;
  data.pot1 = 1;
  data.pot2 = 1;
  data.tSwitch1 = 1;
  data.tSwitch2 = 1;
  data.button1 = 1;
  data.button2 = 1;
  data.button3 = 1;
  data.button4 = 1;
}
