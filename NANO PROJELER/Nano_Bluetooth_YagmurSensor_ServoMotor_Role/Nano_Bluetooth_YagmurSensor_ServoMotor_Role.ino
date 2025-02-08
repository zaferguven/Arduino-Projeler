#include <SoftwareSerial.h>
#include <Servo.h>
const int ldrPin = A0;
const int yagmursensor = 4 , relay1 = 5 , servopin = 6 , relay2 = 7;
int ldrValue = 0;
bool bluetoothControl = false;
Servo shutterServo;

SoftwareSerial bluetooth(10, 11); //Bluetooth RX TX bağlantı pinleri

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  bluetooth.begin(9600);
  Serial.begin(9600);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  bluetoothControl = false;
  shutterServo.attach(servopin);
  shutterServo.write(0);
}

void loop() {
  int rainValue = digitalRead(yagmursensor);
    if (rainValue == LOW) {
      shutterServo.write(90);
    } else {
      shutterServo.write(0);
    }
  
  if (bluetooth.available()){
    char command = bluetooth.read();
    
    if (command == 'A'){
      digitalWrite(relay1, HIGH);
      bluetoothControl = true;
    }
    else if (command == 'B'){
      digitalWrite(relay1, LOW);
      bluetoothControl = false;
    }
    else if (command == 'C'){
      digitalWrite(relay2, HIGH);
    }
    else if (command == 'D'){
      digitalWrite(relay2, LOW);
    }
  }

  if (!bluetoothControl) {
    ldrValue = analogRead(ldrPin);

    if (ldrValue < 400){
      digitalWrite(relay1, HIGH);
    }
    else {
      digitalWrite(relay1, LOW);
    }
  }
  delay(1000);
}
