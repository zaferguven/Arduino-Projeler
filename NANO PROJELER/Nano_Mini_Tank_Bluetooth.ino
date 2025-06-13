#include <SPI.h>
#include <Servo.h>
#define korna 8
#define far 9
#define stoplar 10

Servo servoX;
Servo servoY;

int servoXPosition, servoYPosition, servoX1Position, servoY1Position, veri;

void setup(){
  Serial.begin(9600);
  servoX.attach(5);
  servoY.attach(6);
  pinMode(far, OUTPUT);
  pinMode(stoplar, OUTPUT);
  pinMode(korna, OUTPUT);
  digitalWrite(far, LOW);
  digitalWrite(stoplar, LOW);
  digitalWrite(korna, LOW);
  servoX.write(88);
  servoY.write(88);
}

void loop(){
  if(Serial.available()>0){
    veri = Serial.read();

    // Far ve Stop Işık Kontrol
    if(veri=='A'){
      digitalWrite(far, HIGH);
      digitalWrite(stoplar, HIGH);
    }
    else if(veri=='a'){
      digitalWrite(far, LOW);
      digitalWrite(stoplar, LOW);
    }
  
    // Korna Kontrol
    if(veri=='V'){
      digitalWrite(korna, HIGH);
      delay(500);
      digitalWrite(korna, LOW);
    }
    else if(veri=='v'){
      digitalWrite(korna, HIGH);
      delay(500);
      digitalWrite(korna, LOW);
    }
    

    // Servo motor kontrolü: Sağ, sol, ileri, geri hareketler
    if (veri == 'F') {
      servoX.write(98);
      servoY.write(78);
    }
    else if (veri == 'B') {
      servoX.write(78);
      servoY.write(98);
    }
    else if (veri == 'R') {
      servoX.write(98);
      servoY.write(98);
    }
    else if (veri == 'L') {
      servoX.write(78);
      servoY.write(78);
    }
    else if(veri == 's'){
      servoX.write(88);
      servoY.write(88);
    }
}}
