#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
int led6 = 8;
int led7 = 9;
int led8 = 10;
int led9 = 11;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTON1)
    {
      digitalWrite(led1, !digitalRead(led1));
      if (digitalRead(led1) == HIGH)
      {
        Serial.println("LED 1 yandi");
      }
      else
      {
        Serial.println("LED 1 sondu");
      }
    }
    if (results.value == BUTON2)
    {
      digitalWrite(led2, !digitalRead(led2));
      if (digitalRead(led2) == HIGH)
      {
        Serial.println("LED 2 yandi");
      }
      else
      {
        Serial.println("LED 2 sondu");
      }
    }
    if (results.value == BUTON3)
    {
      digitalWrite(led3, !digitalRead(led3));
      if (digitalRead(led3) == HIGH)
      {
        Serial.println("LED 3 yandi");
      }
      else
      {
        Serial.println("LED 3 sondu");
      }
    }
    if (results.value == BUTON4)
    {
      digitalWrite(led4, !digitalRead(led4));
      if (digitalRead(led4) == HIGH)
      {
        Serial.println("LED 4 yandi");
      }
      else
      {
        Serial.println("LED 4 sondu");
      }
    }
      if (results.value == BUTON5)
    {
      digitalWrite(led5, !digitalRead(led5));
      if (digitalRead(led5) == HIGH)
      {
        Serial.println("LED 5 yandi");
      }
      else
      {
        Serial.println("LED 5 sondu");
      }
    }

      if (results.value == BUTON6)
    {
      digitalWrite(led6, !digitalRead(led6));
      if (digitalRead(led6) == HIGH)
      {
        Serial.println("LED 6 yandi");
      }
      else
      {
        Serial.println("LED 6 sondu");
      }
    }
      if (results.value == BUTON7)
    {
      digitalWrite(led7, !digitalRead(led7));
      if (digitalRead(led7) == HIGH)
      {
        Serial.println("LED 7 yandi");
      }
      else
      {
        Serial.println("LED 7 sondu");
      }
    }
      if (results.value == BUTON8)
    {
      digitalWrite(led8, !digitalRead(led8));
      if (digitalRead(led8) == HIGH)
      {
        Serial.println("LED 8 yandi");
      }
      else
      {
        Serial.println("LED 8 sondu");
      }
    }
    if (results.value == BUTON9)
    {
      digitalWrite(led9, !digitalRead(led9));
      if (digitalRead(led9) == HIGH)
      {
        Serial.println("LED 9 yandi");
      }
      else
      {
        Serial.println("LED 9 sondu");
      }
    }
    if (results.value == BUTON0)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      Serial.println("Tum LED'ler sondu");
    }
    irrecv.resume();
  }
}
