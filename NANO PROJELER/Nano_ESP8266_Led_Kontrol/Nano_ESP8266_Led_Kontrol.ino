#define ag_ismi "wifi adı"
#define ag_sifresi "password"
void setup() {
  Serial.begin(115200); //Seriport'u açıyoruz. Güncellediğimiz 
  Serial.println("AT"); //ESP modülümüz ile bağlantı kurulup kurulmadığını kontrol ediyoruz.
  pinMode(13, OUTPUT);
  delay(3000);
  if (Serial.find("OK")) {
    Serial.println("AT+CWMODE=1");
    delay(2000);
    String baglantiKomutu = String("AT+CWJAP=\"") + ag_ismi + "\",\"" + ag_sifresi + "\"";
    Serial.println(baglantiKomutu);
    delay(5000);
  }
  Serial.print("AT+CIPMUX=1\r\n");
  delay(200);
  Serial.print("AT+CIPSERVER=1,80\r\n");
  delay(1000);
}
void loop() {
  if (Serial.available() > 0) {
    if (Serial.find("+IPD,")) {
      String 
      metin = "<title>Zafer Güven - Akıllı Ev Sistemi</title>";
      metin = "<center><head><h1>ZAFER GÜVEN AKILLI EV SİSTEMİ</h1></head></center>";
      metin += "<br><a href=\" ?pin=on\"><button type='button'>LED ON</button></a>";
      metin += "<br><a href=\" ?pin=off\"><button type='button'>LED OFF</button></a>";
      String cipsend = "AT+CIPSEND=";
      cipsend += "0";
      cipsend += ",";
      cipsend += metin.length();
      cipsend += "\r\n";
      Serial.print(cipsend);
      delay(500);
      Serial.println(metin);
      led_yakma();
      Serial.println("AT+CIPCLOSE=0");
    }
  }
}
void led_yakma() {
  String gelen = "";
  char serialdenokunan;
  while (Serial.available() > 0) {
    serialdenokunan = Serial.read();
    gelen += serialdenokunan;
  }
  Serial.println(gelen);
  if ((gelen.indexOf(":GET /?pin=on") > 1)) {
    digitalWrite(13, HIGH); //ledi yakar
  }
  if ((gelen.indexOf(":GET /?pin=off") > 1)) {
    digitalWrite(13, LOW); //ledi söndürür
  }
}
