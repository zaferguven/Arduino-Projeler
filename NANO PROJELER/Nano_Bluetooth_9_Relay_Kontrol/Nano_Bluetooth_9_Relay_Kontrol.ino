int veri;          //Bluetooth üzerinden okuduğumuz değişken.
int Relay1 = 5;    //Relay 1 çıkış pini
int Relay2 = 6;    //Relay 2 çıkış pini
int Relay3 = 7;    //Relay 3 çıkış pini
int Relay4 = 8;    //Relay 4 çıkış pini
int Relay5 = 9;    //Relay 5 çıkış pini
int Relay6 = 10;   //Relay 6 çıkış pini
int Relay7 = 11;   //Relay 7 çıkış pini
int Relay8 = 12;   //Relay 8 çıkış pini
int Relay9 = 13;   //Relay 9 çıkış pini

void setup() {
  Serial.begin(9600);           //Seri haberleşmeyi başlatıyoruz.
  pinMode(Relay1,OUTPUT);       //Relay 1 çıkış olarak ayarlandı
  pinMode(Relay2,OUTPUT);       //Relay 2 çıkış olarak ayarlandı
  pinMode(Relay3,OUTPUT);       //Relay 3 çıkış olarak ayarlandı
  pinMode(Relay4,OUTPUT);       //Relay 4 çıkış olarak ayarlandı
  pinMode(Relay5,OUTPUT);       //Relay 5 çıkış olarak ayarlandı
  pinMode(Relay6,OUTPUT);       //Relay 6 çıkış olarak ayarlandı
  pinMode(Relay7,OUTPUT);       //Relay 7 çıkış olarak ayarlandı
  pinMode(Relay8,OUTPUT);       //Relay 8 çıkış olarak ayarlandı
  pinMode(Relay9,OUTPUT);       //Relay 9 çıkış olarak ayarlandı
  digitalWrite(Relay1,LOW);     //Relay 1 kapalı başla
  digitalWrite(Relay2,LOW);     //Relay 2 kapalı başla
  digitalWrite(Relay3,LOW);     //Relay 3 kapalı başla
  digitalWrite(Relay4,LOW);     //Relay 4 kapalı başla
  digitalWrite(Relay5,LOW);     //Relay 5 kapalı başla
  digitalWrite(Relay6,LOW);     //Relay 6 kapalı başla
  digitalWrite(Relay7,LOW);     //Relay 7 kapalı başla
  digitalWrite(Relay8,LOW);     //Relay 8 kapalı başla
  digitalWrite(Relay9,LOW);     //Relay 9 kapalı başla
}

void loop() {
  if(Serial.available()>0){ //-------------------- Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read();   //-------------------- Seri haberleşmeden gelen veriyi okuyoruz.
  }
  // RELAY 1
     if (veri == 'a'){digitalWrite(Relay1, HIGH);} //a gelince relay 1 i aç
     if (veri == 'b'){digitalWrite(Relay1, LOW);}  //b gelince relay 1 i kapat
  // RELAY 2
     if (veri == 'c'){digitalWrite(Relay2, HIGH);} //c gelince relay 2 yi aç
     if (veri == 'd'){digitalWrite(Relay2, LOW);}  //d gelince relay 2 yi kapat
  // RELAY 3
     if (veri == 'e'){digitalWrite(Relay3, HIGH);} //e gelince relay 3 ü aç
     if (veri == 'f'){digitalWrite(Relay3, LOW);}  //f gelince relay 3 ü kapat
  // RELAY 4
     if (veri == 'g'){digitalWrite(Relay4, HIGH);} //g gelince relay 4 ü aç
     if (veri == 'h'){digitalWrite(Relay4, LOW);}  //h gelince relay 4 ü kapat
  // RELAY 5
     if (veri == 'i'){digitalWrite(Relay5, HIGH);} //i gelince relay 5 i aç
     if (veri == 'j'){digitalWrite(Relay5, LOW);}  //j gelince relay 5 i kapat
  // RELAY 6
     if (veri == 'k'){digitalWrite(Relay6, HIGH);} //k gelince relay 6 yı aç
     if (veri == 'l'){digitalWrite(Relay6, LOW);}  //l gelince relay 6 yı kapat
  // RELAY 7
     if (veri == 'm'){digitalWrite(Relay7, HIGH);} //m gelince relay 7 yi aç
     if (veri == 'n'){digitalWrite(Relay7, LOW);}  //n gelince relay 7 yi kapat
  // RELAY 8
     if (veri == 'o'){digitalWrite(Relay8, HIGH);} //o gelince relay 8 i aç
     if (veri == 'p'){digitalWrite(Relay8, LOW);}  //p gelince relay 8 i kapat
  // RELAY 9
     if (veri == 'r'){digitalWrite(Relay9, HIGH);} //r gelince relay 9 u aç
     if (veri == 's'){digitalWrite(Relay9, LOW);}  //s gelince relay 9 u kapat
  // TÜM RELAYLARI KAPAT
     if (veri == 't'){ //--------------------------- t gelince tüm relayları kapat
      digitalWrite(Relay1, LOW);
      digitalWrite(Relay2, LOW);
      digitalWrite(Relay3, LOW);
      digitalWrite(Relay4, LOW);
      digitalWrite(Relay5, LOW);
      digitalWrite(Relay6, LOW);
      digitalWrite(Relay7, LOW);
      digitalWrite(Relay8, LOW);
      digitalWrite(Relay9, LOW);
        }
}
