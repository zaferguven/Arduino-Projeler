#include <OLED_I2C.h>
extern uint8_t SmallFont[];
int i  = 10;
int m = 207;
int page = 1;
int x = 0; int y = 0;
int son = 0; int son2 = 0; int son3 = 0;
int diger = 1; int diger2 = 1; int diger3 = 1;
volatile boolean inv = false;
volatile boolean tus = false;
volatile boolean tus3 = false;
volatile boolean inv2 = false;

OLED  myOLED(SDA, SCL, 8);
void setup() {
  myOLED.begin(); myOLED.clrScr();

  pinMode(2, INPUT);
  myOLED.setFont(SmallFont);
}

void loop() {
  int z = digitalRead(4);
  int y = digitalRead(3);
  int x = digitalRead(2);

  geri();
  if (page == 1) {
    myOLED.clrScr();
    myOLED.invertText(true);
    myOLED.print(" ANA MENU ", CENTER, 0);
    myOLED.invertText(false);
    myOLED.print("EKRAN MODU :", 10, 10);
    myOLED.print("PARLAKLIK", 10, 25);
    myOLED.print("RC MODELLER", 10, 40);
    if (inv2 == true && page == 1)
      myOLED.print("ON", 85, 10);
    if (inv2 == false && page == 1)
      myOLED.print("OFF", 85, 10);
    myOLED.print(">", 0, i); myOLED.update();
    yon();
  }

  secim();
  if (page == 2)
  {
    myOLED.clrScr();
    myOLED.invertText(true);
    myOLED.print(" RC MODELLER ", CENTER, 0);
    myOLED.invertText(false);
    myOLED.print("UCAK", 10, 10);
    myOLED.print("ARABA", 10, 25);
    myOLED.print("TEKNE", 10, 40);
    myOLED.print(">", 0, i); myOLED.update();
    yon();
  }
  
  invertFunc();
  if (i == 25 && page == 1 && y == 1 )
  {
    page = 3;
  }
  if (page == 3 )
  {
    myOLED.clrScr();
    myOLED.print("PARLAKLIK :", 0, i);
    myOLED.printNumI(m, 70, 25);
    myOLED.update();
    if (y == 1 && page == 3)
      parlaklikAyar();
  }
  myOLED.setBrightness(m);
}

void parlaklikAyar()
{
  int y = digitalRead(3);
  if (y == 0)
    diger3 = 0;
  if (y == 1 && diger3 == 0)
  {
    son3 = 1;
    tus3 = true;
  }
  if (son3 == 1 && tus3 == true)
  { diger3 = 1;
    myOLED.clrScr();
    myOLED.update();
    m = m + 20;
    tus3 = false; son3 = 0;

    if (m > 255)
    {
      m = 0;
    }
  }
}

void invertFunc()
{
  int y = digitalRead(3);
  if (i == 10 && page == 1 && y == 1 && son2 == 0)
  {
    son2 = 1;
    if (inv2 == false)
    { inv2 = true;
    }
    else if (inv2 == true) {
      inv2 = false;
    }
  }
  else if (i == 10 && page == 1 && y == 0 && son2 == 1)
    son2 = 0;
  if (inv2 == true)
    myOLED.invert(true);
  if (inv2 == false)
    myOLED.invert(false);

}
void geri()
{ int z = digitalRead(4);
  if (z == 1)
  { i = 10;

    page = page - 1;
    if (page < 1)
      page = 1;
  }
}
void secim()
{
  int y = digitalRead(3);
  if (y == 1 && i != 10 && i != 25)
  {
    page = 2;
    i = 10;
  }
}

void yon()
{ int x = digitalRead(2);
  if (x == 0)
    diger = 0;
  if (x == 1 && diger == 0)
  {
    son = 1;
    tus = true;
  }
  if (son == 1 && tus == true)
  { diger = 1;
    myOLED.clrScr();
    myOLED.update();
    i = i + 15;
    tus = false; son = 0;

    if (i > 40)
    {
      i = 10;
    }
  }
}
