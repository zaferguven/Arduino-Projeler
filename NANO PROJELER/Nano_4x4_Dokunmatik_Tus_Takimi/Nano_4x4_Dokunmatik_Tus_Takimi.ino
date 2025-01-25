#define SCL_PIN A5
#define SDO_PIN A4
byte buton;

void setup(){
  Serial.begin(9600);
  pinMode(SCL_PIN, OUTPUT);  
  pinMode(SDO_PIN, INPUT); 
}

void loop()
{
  buton = butonoku();
  if (buton)
  Serial.println(buton);
  delay(250);
}

byte butonoku(void)
{
  byte sayi;
  byte butondurum = 0;
    for(sayi = 1; sayi <= 16; sayi++){
      digitalWrite(SCL_PIN, LOW);
      if (!digitalRead(SDO_PIN))
      butondurum = sayi;
      digitalWrite(SCL_PIN, HIGH);
  }
  return butondurum;
}
