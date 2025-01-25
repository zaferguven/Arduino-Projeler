#include <SD.h> // Sd kart kutuphanesi
#define SD_ChipSelectPin 10 //mega icin cs pini.
#include <TMRpcm.h> // waw okuma kutuphanesi
#include "Wire.h"
#include <TEA5767Radio.h>
#include "VoiceRecognitionV3.h"
TEA5767Radio radio = TEA5767Radio();
TMRpcm tmrpcm;
VR myVR(2,3);
String gelenses;uint8_t records[7]; // save record
uint8_t buf[64];

int led1 = 4;
int led2 = 5;
int pc = 6;

#define lamba (0)
#define masalamba (1)
#define bilgisayar (2)
#define lambakapat (3)
#define masalambakapat (4)
#define kapat (5)
#define ac (6)

void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup() {
  { 
  Wire.begin();
  radio.setFrequency(93.0); // pick your own frequency
  }
  tmrpcm.speakerPin = 9;
  tmrpcm.volume(100);
  pinMode(SD_ChipSelectPin,OUTPUT);
  if (!SD.begin(SD_ChipSelectPin)) { 
  Serial.println("SD okuyamadi"); 
  return;
  } 
  pinMode(9,OUTPUT); //speaker çıkışı
  tmrpcm.play("0.wav");
  
  myVR.begin(9600);
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pc, OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(pc,LOW);
  
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);}
  if(myVR.load((uint8_t)lamba) >= 0){
    Serial.println("lamba");}
  if(myVR.load((uint8_t)masalamba) >= 0){
    Serial.println("masalamba");}
  if(myVR.load((uint8_t)bilgisayar) >= 0){
    Serial.println("bilgisayar");}
  if(myVR.load((uint8_t)lambakapat) >= 0){
    Serial.println("lambakapat");}
  if(myVR.load((uint8_t)masalambakapat) >= 0){
    Serial.println("masalambakapat");}
  if(myVR.load((uint8_t)kapat) >= 0){
    Serial.println("kapat");}
  if(myVR.load((uint8_t)ac) >= 0){
    Serial.println("ac");}
 }

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case lamba:
        digitalWrite(led1, HIGH);
        delay(500);
        tmrpcm.play("1.wav");
        break;
      case masalamba:
        digitalWrite(led2, HIGH);
        delay(500);
        tmrpcm.play("3.wav");
        break;
      case bilgisayar:
        digitalWrite(pc, HIGH);
        delay(500);
        digitalWrite(pc, LOW);
        delay(500);
        tmrpcm.play("5.wav");
        break;
      case lambakapat:
        digitalWrite(led1, LOW);
        delay(500);
        tmrpcm.play("2.wav");
        break;
      case masalambakapat:
        digitalWrite(led2, LOW);
        delay(500);
        tmrpcm.play("4.wav");
        break;
      case kapat:
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        delay(500);
        tmrpcm.play("6.wav");
        break;
      case ac:
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(500);
        tmrpcm.play("7.wav");
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    printVR(buf);
  }
}
