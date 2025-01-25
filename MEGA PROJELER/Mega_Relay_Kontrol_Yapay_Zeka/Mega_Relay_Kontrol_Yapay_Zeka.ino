#include <SD.h> // Sd kart kutuphanesi
#define SD_ChipSelectPin 53 //mega icin cs pini.
#include <TMRpcm.h> // waw okuma kutuphanesi
#include <SPI.h>// seri haberleşme kütüphanesi
#include "Wire.h"
#include <TEA5767Radio.h>
TEA5767Radio radio = TEA5767Radio();
TMRpcm tmrpcm; 
String gelenses;
int lamba = 2;
int masalambasi = 3;
int bilgisayar = 4;

void setup() {
{ 
  Wire.begin();
  radio.setFrequency(93.0); // pick your own frequency
}
  Serial.begin(57600);
  pinMode(SD_ChipSelectPin,OUTPUT);
 Serial.begin(9600);
 tmrpcm.speakerPin = 11;
 tmrpcm.volume(100);
 Serial.begin(9600);
 if (!SD.begin(SD_ChipSelectPin)) { 
 Serial.println("SD okuyamadi"); 
 return; 

 }
pinMode(2,OUTPUT); //lamba çıkışı
pinMode(3,OUTPUT); //masa lambası çıkışı
pinMode(4,OUTPUT); //bilgisayar açma
pinMode(11,OUTPUT); //speaker çıkışı
/*pinMode(5,OUTPUT); //
pinMode(6,OUTPUT); //
pinMode(7,OUTPUT); //
pinMode(8,OUTPUT); //
pinMode(9,OUTPUT); //
pinMode(10,OUTPUT); //
pinMode(22,OUTPUT); //
pinMode(24,OUTPUT); //
pinMode(26,OUTPUT); //
pinMode(28,OUTPUT); //
pinMode(30,OUTPUT); //
pinMode(31,OUTPUT); //
pinMode(32,OUTPUT); //
pinMode(33,OUTPUT); //
pinMode(34,OUTPUT); //
pinMode(35,OUTPUT); //
pinMode(36,OUTPUT); //
pinMode(37,OUTPUT); //
pinMode(38,OUTPUT); //
pinMode(39,OUTPUT); //
pinMode(40,OUTPUT); //
pinMode(41,OUTPUT); //
pinMode(42,OUTPUT); //
pinMode(43,OUTPUT); //
pinMode(44,OUTPUT); //
pinMode(45,OUTPUT); //
pinMode(46,OUTPUT); //
pinMode(47,OUTPUT); //
pinMode(48,OUTPUT); //
pinMode(49,OUTPUT); //*/

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(11, LOW);
/*digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(22, LOW);
digitalWrite(24, LOW);
digitalWrite(26, LOW);
digitalWrite(28, LOW);
digitalWrite(30, LOW);
digitalWrite(31, LOW);
digitalWrite(32, LOW);
digitalWrite(33, LOW);
digitalWrite(34, LOW);
digitalWrite(35, LOW);
digitalWrite(36, LOW);
digitalWrite(37, LOW);
digitalWrite(38, LOW);
digitalWrite(39, LOW);
digitalWrite(40, LOW);
digitalWrite(41, LOW);
digitalWrite(42, LOW);
digitalWrite(43, LOW);
digitalWrite(44, LOW);
digitalWrite(45, LOW);
digitalWrite(46, LOW);
digitalWrite(47, LOW);
digitalWrite(48, LOW);
digitalWrite(49, LOW);*/

tmrpcm.play("0.wav");
}

void loop() {    
   while (Serial.available()){ 
 delay(10); 
 char c = Serial.read(); 
 if (c == '#') {break;} 
 gelenses += c; 
 } 
 if (gelenses.length() > 0) {
 Serial.println(gelenses); 

  if(gelenses == "*adın ne"||gelenses == "*ismin ne"){ tmrpcm.play("1.wav");} 
  else if(gelenses == "*tekbir"){ tmrpcm.play("2.wav");}
  else if(gelenses == "*Şarkımı çal"){ tmrpcm.play("3.wav");}
  /*else if(gelenses == "*"){ tmrpcm.play("4.wav");}
  else if(gelenses == "*"){ tmrpcm.play("5.wav");}
  else if(gelenses == "*"){ tmrpcm.play("6.wav");}
  else if(gelenses == "*"){ tmrpcm.play("7.wav");}
  else if(gelenses == "*"){ tmrpcm.play("8.wav");}
  else if(gelenses == "*"){ tmrpcm.play("9.wav");}
  else if(gelenses == "*"){ tmrpcm.play("10.wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}
  else if(gelenses == "*"||gelenses == "*"||gelenses == "*"){ tmrpcm.play(".wav");}*/
  else if(gelenses == "*Lambayı aç") {digitalWrite(lamba, HIGH); tmrpcm.play("31.wav");}
  else if(gelenses == "*Lambayı kapat") {digitalWrite(lamba, LOW); tmrpcm.play("32.wav");}
  else if(gelenses == "*masa lambasını aç") {digitalWrite(masalambasi, HIGH); tmrpcm.play("33.wav");}
  else if(gelenses == "*masa lambasını kapat") {digitalWrite(masalambasi, LOW); tmrpcm.play("34.wav");}
  else if(gelenses == "*Bilgisayarı aç") {digitalWrite(bilgisayar, HIGH); delay(50); digitalWrite(bilgisayar, LOW); tmrpcm.play("35.wav");}
  else if(gelenses == "*Işıkları aç") {digitalWrite(lamba, HIGH); digitalWrite(masalambasi, HIGH); tmrpcm.play("36.wav");}
  else if(gelenses == "*Işıkları kapat") {digitalWrite(lamba, LOW); digitalWrite(masalambasi, LOW); tmrpcm.play("37.wav");}
 else {tmrpcm.play("geri.wav");  }
gelenses="";}

  delay(1000); // every second
} //resetleme

//---------------------------------------------------------------------------------------------------------------------------------
