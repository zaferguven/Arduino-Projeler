int veri;
int sure=3;
int Relay1=2,Relay2=3,Relay3=4,Relay4=5,IN1=6,IN2=7,IN3=8,IN4=9,Relay5=10,Relay6=11,Relay7=12;

void setup(){
Serial.begin(9600);
pinMode(Relay1,OUTPUT);
pinMode(Relay2,OUTPUT);
pinMode(Relay3,OUTPUT);
pinMode(Relay4,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(Relay5,OUTPUT);
pinMode(Relay6,OUTPUT);
pinMode(Relay7,OUTPUT);
digitalWrite(Relay1,LOW);
digitalWrite(Relay2,LOW);
digitalWrite(Relay3,LOW);
digitalWrite(Relay4,LOW);
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
digitalWrite(Relay5,LOW);
digitalWrite(Relay6,LOW);
digitalWrite(Relay7,LOW);
}

void loop(){
  if(Serial.available()>0){
  veri = Serial.read();

    //Relay1
    if(veri == 'a'){digitalWrite(Relay1,HIGH);}
    if(veri == 'b'){digitalWrite(Relay1,LOW);}

    //Relay2
    if(veri == 'c'){digitalWrite(Relay2,HIGH);}
    if(veri == 'd'){digitalWrite(Relay2,LOW);}

    //Relay3
    if(veri == 'e'){digitalWrite(Relay3,HIGH);}
    if(veri == 'f'){digitalWrite(Relay3,LOW);}

    //Relay4
    if(veri == 'g'){digitalWrite(Relay4,HIGH);}
    if(veri == 'h'){digitalWrite(Relay4,LOW);}

    //Step Motor İleri
    if(veri == 'i'){SaatYonu(512);}

    //Step Motor Geri
    if(veri == 'j'){SaatYonuTers(512);}

    //Relay5 - Kırmızı Led
    if(veri == 'k'){digitalWrite(Relay5,HIGH);}
    if(veri == 'l'){digitalWrite(Relay5,LOW);}

    //Relay6 - Sarı Led
    if(veri == 'm'){digitalWrite(Relay6,HIGH);}
    if(veri == 'n'){digitalWrite(Relay6,LOW);}

    //Relay7 - Yeşil Led
    if(veri == 'o'){digitalWrite(Relay7,HIGH);}
    if(veri == 'p'){digitalWrite(Relay7,LOW);}

    //Tüm Işıkları Açma
    if(veri == 'r'){
      digitalWrite(Relay5,HIGH);
      digitalWrite(Relay6,HIGH);
      digitalWrite(Relay7,HIGH);
      }

    //Tüm Işıkları Kapatma
    if(veri == 's'){
      digitalWrite(Relay5,LOW);
      digitalWrite(Relay6,LOW);
      digitalWrite(Relay7,LOW);
      }
      
    delay(100);
  }
}

void SaatYonu(int adim) {
  for (int i = 0; i < adim; i++) {
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
  }
}

void SaatYonuTers(int adim) {
  for (int i = 0; i < adim; i++) {
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
  }
}
