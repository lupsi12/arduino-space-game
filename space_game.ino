#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif12pt7b.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3D
#define basButon 19
#define led1 13
#define led2 12
#define led3 11
#define silahled1 10
#define silahled2 9
#define silahled3 8
#define buzzer 14
#define displayA 22
#define displayB 23
#define displayC 24
#define displayD 25
#define displayE 26
#define displayF 27
#define displayG 28
#define displayA1 29
#define displayB1 30
#define displayC1 31
#define displayD1 32
#define displayE1 33
#define displayF1 34
#define displayG1 35
#define displayA2 36
#define displayB2 37
#define displayC2 38
#define displayD2 39
#define displayE2 40
#define displayF2 41
#define displayG2 42

const unsigned char nuzaycopu[] PROGMEM = {
  B00011000,
  B00100110,
  B00101001,
  B01000010,
  B01010010,
  B10010100,
  B01100100,
  B00011000
};
const unsigned char nroket[] PROGMEM = {
  B01110000,
  B10101100,
  B10000010,
  B01000101,
  B01000101,
  B10000010,
  B10101100,
  B01110000
};
const unsigned char nmeteor[] PROGMEM = {
  B00111000,
  B01000100,
  B10010010,
  B10100001,
  B10100101,
  B10000001,
  B01001010,
  B00110100
};
const unsigned char ncanodul[] PROGMEM = {
  B00111100,
  B01000110,
  B01010101,
  B01111101,
  B01010101,
  B01000110,
  B00111100,
  B00000000
};
const unsigned char nates[] PROGMEM = {
  B00000000,
  B00000000,
  B11111110,
  B10000101,
  B10000101,
  B11111110,
  B00000000,
  B00000000
};
const unsigned char hap[] PROGMEM = {
  B00000000,
  B00001110,
  B00010110,
  B00110110,
  B01001100,
  B01001000,
  B01110000,
  B00000000
};
boolean menuu = false;
int whilehiz = 1000;

boolean menumillesbool = false;
unsigned long menumilles = 0;

boolean gamemillesbool = false;
unsigned long gamemillesson = 0;
unsigned long gamemillesilk = 0;

unsigned long hizlanmamilles = 0;
unsigned long sayachizlanma = 1;

int platformhiz ;
unsigned long platformsure = 0;
boolean hizlanma = false;

boolean dokunulmazmillesbool = false;
unsigned long dokunulmazmillesson = 0;
unsigned long dokunulmazmillesilk = 0;

boolean engelmillesbool = false;
unsigned long engelmillesson = 0;
unsigned long engelmillesilk = 0;

int selected = 0;
int entered = -1;

int oyunMatris[8][16];

boolean matris = false;

int x = random(8);
int y = 0;
int skor = 0;
int d1 = 0;
int d2 = 0;
int d3 = 0;

int atesX;
int atesY;
boolean ates = false;
int ateshak = 3;

int odulX;
int odulY;
boolean odul = false;
int odulsure = 0;

int dokunulmazX;
int dokunulmazY;
boolean dokunulmaz = false;
int dokunulmazsure = 0;
boolean beklet = false;

int xmeteor;
int ymeteor;
boolean meteor = false;
int meteorguc = 2;

int copX;
int copY;
boolean cop = false;
boolean cop1 = false;

int hiz = 1;

int bitis = 1;

int can = 3;

int sayac = 0;

const char *renk[2] = {
  " WHITE ",
  " BLACK "
};

int potPin = A1;
int pot_deger = 0;
boolean a1 = false;
boolean a2 = false;

boolean meteorry = false;
boolean sil = false;
int meteoryeniX;
int meteoryeniY;
unsigned long yenimeteorolusturmasayisi = 1;

void menusifirlamalari(void){
 whilehiz = 1000;
 menumillesbool = false;
 menumilles = 0;
 gamemillesbool = false;
 gamemillesson = 0;
 gamemillesilk = 0;
 hizlanmamilles = 0;
 sayachizlanma = 1;
 platformhiz ;
 platformsure = 0;
 hizlanma = false;
 dokunulmazmillesbool = false;
 dokunulmazmillesson = 0;
 dokunulmazmillesilk = 0;
 engelmillesbool = false;
 engelmillesson = 0;
 engelmillesilk = 0;
 selected = 0;
 entered = -1;
 for(int i=0;i<8;i++){
      for(int j=0;j<16;j++){
        oyunMatris[i][j] = 0;
      }
 }
 matris = false;
 x = random(8);
 y = 0;
 skor = 0;
 d1 = 0;
 d2 = 0;
 d3 = 0;
 atesX;
 atesY;
 ates = false;
 ateshak = 3;
 odulX;
 odulY;
 odul = false;
 odulsure = 0;
 dokunulmazX;
 dokunulmazY;
 dokunulmaz = false;
 dokunulmazsure = 0;
 beklet = false;
 xmeteor;
 ymeteor;
 meteor = false;
 meteorguc = 2;
 copX;
 copY;
 cop = false;
 cop1 = false;
 hiz = 1;
 bitis = 1;
 can = 3;
 sayac = 0;
 a1 = false;
 a2 = false;
 meteorry = false;
 sil = false;
 meteoryeniX;
 meteoryeniY;
 yenimeteorolusturmasayisi = 1;
 menuu = false;
}
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void displaygosterim(int secim) {
  switch (secim) {
    case 0:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, HIGH);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, LOW);
      break;
    case 1:
      digitalWrite(displayA, LOW);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, LOW);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, LOW);
      digitalWrite(displayG, LOW);
      break;
    case 2:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, LOW);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, HIGH);
      digitalWrite(displayF, LOW);
      digitalWrite(displayG, HIGH);
      break;
    case 3:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, LOW);
      digitalWrite(displayG, HIGH);
      break;
    case 4:
      digitalWrite(displayA, LOW);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, LOW);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, HIGH);
      break;
    case 5:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, LOW);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, HIGH);
      break;
    case 6:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, LOW);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, HIGH);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, HIGH);
      break;
    case 7:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, LOW);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, LOW);
      digitalWrite(displayG, HIGH);
      break;
    case 8:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, HIGH);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, HIGH);
      break;
    case 9:
      digitalWrite(displayA, HIGH);
      digitalWrite(displayB, HIGH);
      digitalWrite(displayC, HIGH);
      digitalWrite(displayD, HIGH);
      digitalWrite(displayE, LOW);
      digitalWrite(displayF, HIGH);
      digitalWrite(displayG, HIGH);
      break;
  }
}
void displaygosterim1(int secim) {
  switch (secim) {
    case 0:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, LOW);
      break;
    case 1:
      digitalWrite(displayA1, LOW);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, LOW);
      break;
    case 2:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, LOW);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 3:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 4:
      digitalWrite(displayA1, LOW);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 5:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, LOW);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 6:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, LOW);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 7:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, LOW);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, LOW);
      digitalWrite(displayG1, HIGH);
      break;
    case 8:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, HIGH);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
    case 9:
      digitalWrite(displayA1, HIGH);
      digitalWrite(displayB1, HIGH);
      digitalWrite(displayC1, HIGH);
      digitalWrite(displayD1, HIGH);
      digitalWrite(displayE1, LOW);
      digitalWrite(displayF1, HIGH);
      digitalWrite(displayG1, HIGH);
      break;
  }
}
void displaygosterim2(int secim) {
  switch (secim) {
    case 0:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, LOW);
      break;
    case 1:
      digitalWrite(displayA2, LOW);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, LOW);
      break;
    case 2:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, LOW);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 3:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 4:
      digitalWrite(displayA2, LOW);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 5:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, LOW);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 6:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, LOW);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 7:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, LOW);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, LOW);
      digitalWrite(displayG2, HIGH);
      break;
    case 8:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, HIGH);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
    case 9:
      digitalWrite(displayA2, HIGH);
      digitalWrite(displayB2, HIGH);
      digitalWrite(displayC2, HIGH);
      digitalWrite(displayD2, HIGH);
      digitalWrite(displayE2, LOW);
      digitalWrite(displayF2, HIGH);
      digitalWrite(displayG2, HIGH);
      break;
  }
}
void Game(void) {
  unsigned long whilemillis = 0;  
  gamemillesilk = millis();
  int asss;
  asss = analogRead(A0);
  if (asss >= 425) {  // karanlık{
    renk[0] = "BLACK";
    a1 = true;
    a2 = false;
  }
  if (asss < 425) {  // karanlık{
    renk[1] = "WHITE";
    a2 = true;
    a1 = false;
  }
  display.clearDisplay();
  if (a1 == true) {
    display.fillScreen(BLACK);
  } else if (a2 == true) {
    display.fillScreen(WHITE);
  }
  pot_deger = analogRead(potPin);
  int bas = digitalRead(basButon);
  if (can == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  if (ateshak == 3) {
    digitalWrite(silahled1, HIGH);
    digitalWrite(silahled2, HIGH);
    digitalWrite(silahled3, HIGH);
  }
  if (sayac == 14) {
    if(ates!=3)
    ateshak++;
    if (ateshak == 1)
      digitalWrite(silahled3, HIGH);
    if (ateshak == 2)
      digitalWrite(silahled2, HIGH);
    if (ateshak == 3)
      digitalWrite(silahled1, HIGH);
    if(can!=3)
    can++;
    if (can == 1)
      digitalWrite(led3, HIGH);
    if (can == 2)
      digitalWrite(led2, HIGH);
    if (can == 3)
      digitalWrite(led1, HIGH);
    sayac = 0;
  }
  if (a1 == true) {
    display.drawPixel(50, 30, 1);
    display.drawPixel(30, 17, 1);
    display.drawPixel(60, 18, 1);
    display.drawPixel(55, 16, 1);
    display.drawPixel(25, 43, 1);
    display.drawPixel(100, 43, 1);
    display.drawPixel(117, 52, 1);
    display.drawPixel(14, 49, 1);
    display.drawPixel(24, 24, 1);
    display.drawPixel(78, 36, 1);
    display.drawPixel(80, 57, 1);
    display.drawPixel(107, 11, 1);
    display.drawPixel(150, 11, 1);
    display.drawPixel(5, 5, 1);
    display.drawPixel(8, 7, 1);
    display.drawPixel(70, 12, 1);
    display.drawPixel(10, 56, 1);
    display.drawPixel(70, 25, 1);
  }
  if (a2 == true) {
    display.drawPixel(50, 30, 0);
    display.drawPixel(30, 17, 0);
    display.drawPixel(60, 18, 0);
    display.drawPixel(55, 16, 0);
    display.drawPixel(25, 43, 0);
    display.drawPixel(100, 43, 0);
    display.drawPixel(117, 52, 0);
    display.drawPixel(14, 49, 0);
    display.drawPixel(24, 24, 0);
    display.drawPixel(78, 36, 0);
    display.drawPixel(80, 57, 0);
    display.drawPixel(107, 11, 0);
    display.drawPixel(150, 11, 0);
    display.drawPixel(5, 5, 0);
    display.drawPixel(8, 7, 0);
    display.drawPixel(70, 12, 0);
    display.drawPixel(10, 56, 0);
    display.drawPixel(70, 25, 0);
  }
  if (pot_deger < 256) {
    if (x > 0) {
      x--;
      skor += 1;
      d1 = skor % 10;
      d2 = skor % 100;
      d2 = d2 / 10;
      d3 = skor / 100;
      displaygosterim(d3);
      displaygosterim1(d2);
      displaygosterim2(d1);
      delay(50);
    }
  }
  if (pot_deger >= 256 && pot_deger < 512) {
    if (x < 7) {
      x++;
      skor += 1;
      d1 = skor % 10;
      d2 = skor % 100;
      d2 = d2 / 10;
      d3 = skor / 100;
      displaygosterim(d3);
      displaygosterim1(d2);
      displaygosterim2(d1);
      delay(50);
    }
  }
  if (bas == 0 && ates == false && ateshak > 0) {
    atesX = x;
    atesY = y;
    ates = true;
    ateshak--;
    delay(50);
  };
  if (ateshak == 2)
    digitalWrite(silahled1, LOW);
  if (ateshak == 1)
    digitalWrite(silahled2, LOW);
  if (ateshak == 0)
    digitalWrite(silahled3, LOW);
  if (meteor == false) {
    do {
      xmeteor = random(8);
      ymeteor = 15;
    } while ((xmeteor == copX && ymeteor == copY) || (xmeteor + 1 == copX && ymeteor == copY) || (xmeteor - 1 == copX && ymeteor == copY) || (xmeteor == dokunulmazX && ymeteor == dokunulmazY) || (xmeteor + 1 == dokunulmazX && ymeteor == dokunulmazY) || (xmeteor - 1 == dokunulmazX && ymeteor == dokunulmazY) || (xmeteor == odulX && ymeteor == odulY) || (xmeteor + 1 == odulX && ymeteor == odulY) || (xmeteor - 1 == copX && ymeteor == odulY));
    meteor = true;
    meteorguc = 2;
    sayac++;
  }
  if (cop1 == false) {
    do {
      copX = random(8);
      copY = 15;
    } while ((xmeteor == copX && ymeteor == copY) || (xmeteor + 1 == copX && ymeteor == copY) || (xmeteor - 1 == copX && ymeteor == copY) || (dokunulmazX == copX && dokunulmazY == copY) || (dokunulmazX + 1 == copX && dokunulmazY == copY) || (dokunulmazX - 1 == copX && dokunulmazY == copY) || (odulX == copX && odulY == copY) || (odulX + 1 == copX && odulY == copY) || (odulX - 1 == copX && odulY == copY));
    cop1 = true;
    cop = true;
    sayac++;
  }

  if (odul == false && odulsure > 5 && can < 3) {
    odul = true;
    do {
      odulX = random(8);
      odulY = 15;
    } while ((xmeteor == odulX && ymeteor == odulY) || (xmeteor - 1 == odulX && ymeteor == odulY) || (xmeteor + 1 == odulX && ymeteor == odulY) || (dokunulmazX == odulX && dokunulmazY == odulY) || (dokunulmazX - 1 == odulX && dokunulmazY == odulY) || (dokunulmazX + 1 == odulX && dokunulmazY == odulY) || (copX - 1 == odulX && copY == odulY) || (copX + 1 == odulX && copY == odulY) || (copX == odulX && copY == odulY));
  }
  if (dokunulmaz == false && dokunulmazsure > 10 && can < 2) {
    dokunulmaz = true;
    do {
      dokunulmazX = random(8);
      dokunulmazY = 15;
    } while ((xmeteor == dokunulmazX && ymeteor == dokunulmazY) || (xmeteor - 1 == dokunulmazX && ymeteor == dokunulmazY) || (xmeteor + 1 == dokunulmazX && ymeteor == dokunulmazY) || (dokunulmazX == odulX && dokunulmazY == odulY) || (dokunulmazX == odulX - 1 && dokunulmazY == odulY) || (dokunulmazX == odulX + 1 && dokunulmazY == odulY) || (copX - 1 == dokunulmazX && copY == dokunulmazY) || (copX + 1 == dokunulmazX && copY == dokunulmazY) || (copX == dokunulmazX && copY == dokunulmazY));
  }
  if (a1 == true) {
    display.drawBitmap(y * 8, x * 8, nroket, 8, 8, WHITE);
    if (meteor == true) {
      display.drawBitmap(ymeteor * 8, xmeteor * 8, nuzaycopu, 8, 8, WHITE);
    }
    if (cop == true) {
      display.drawBitmap(copY * 8, copX * 8, nmeteor, 8, 8, WHITE);
    }
    if (ates == true) {
      display.drawBitmap(atesY * 8, atesX * 8, nates, 8, 8, WHITE);
    }
    if (odul == true) {
      display.drawBitmap(odulY * 8, odulX * 8, ncanodul, 8, 8, WHITE);
    }
    if (dokunulmaz == true) {
      display.drawBitmap(dokunulmazY * 8, dokunulmazX * 8, hap, 8, 8, WHITE);
    }
  }
  if (a2 == true) {
    display.drawBitmap(y * 8, x * 8, nroket, 8, 8, BLACK);
    if (meteor == true) {
      display.drawBitmap(ymeteor * 8, xmeteor * 8, nuzaycopu, 8, 8, BLACK);
    }
    if (cop = true) {
      display.drawBitmap(copY * 8, copX * 8, nmeteor, 8, 8, BLACK);
    }
    if (ates == true) {
      display.drawBitmap(atesY * 8, atesX * 8, nates, 8, 8, 0);
    }
    if (odul == true) {
      display.drawBitmap(odulY * 8, odulX * 8, ncanodul, 8, 8, BLACK);
    }
    if (dokunulmaz == true) {
      display.drawBitmap(dokunulmazY * 8, dokunulmazX * 8, hap, 8, 8, BLACK);
    }
  }
  MATRIS();
  if (ates == true && dokunulmaz == true && ((atesY + 1 == dokunulmazY && atesX == dokunulmazX) || (atesY == dokunulmazY && atesX == dokunulmazX) || (atesY - 1 == dokunulmazY && atesX == dokunulmazX))) {
    ates = false;
    dokunulmaz = false;
    dokunulmazsure = 0;
    beklet = true;
    if (dokunulmazmillesbool == false) {
      dokunulmazmillesilk = millis();
      dokunulmazmillesbool = true;
    }
  }
  if (dokunulmaz == true && (dokunulmazX == x && dokunulmazY == y)) {
    dokunulmaz = false;
    dokunulmazsure = 0;
    beklet = true;
    if (dokunulmazmillesbool == false) {
      dokunulmazmillesilk = millis();
      dokunulmazmillesbool = true;
    }
  }
  if (dokunulmazmillesbool == true) {
    dokunulmazmillesson = millis();
    if ((dokunulmazmillesson - dokunulmazmillesilk) > 3000) {
      dokunulmazmillesbool = false;
      beklet = false;
    }
  }
  if (ates == true && odul == true && ((atesY + 1 == odulY && atesX == odulX) || (atesY == odulY && atesX == odulX) || (atesY - 1 == odulY && atesX == odulX))) {
    if(can!=3)
    can++;
    if (can == 1)
      digitalWrite(led3, HIGH);
    if (can == 2)
      digitalWrite(led2, HIGH);
    if (can == 3)
      digitalWrite(led1, HIGH);
    ates = false;
    odul = false;
    odulsure = 0;
  }
  if (odul == true && (odulX == x && odulY == y)) {
    if(can!=3)
    can++;
    if (can == 1)
      digitalWrite(led3, HIGH);
    if (can == 2)
      digitalWrite(led2, HIGH);
    if (can == 3)
      digitalWrite(led1, HIGH);
    odul = false;
    odulsure = 0;
  }
  if (ates == true && meteor == true && ((atesY + 1 == ymeteor && atesX == xmeteor) || (atesY == ymeteor && atesX == xmeteor) || (atesY - 1 == ymeteor && atesX == xmeteor))) {
    //skor++;
    ates = false;
    meteorguc--;
    if (meteorguc == 0)
      meteor = false;
  }
  if (ates == true && cop == true && ((atesY + 1 == copY && atesX == copX) || (atesY == copY && atesX == copX) || (atesY - 1 == copY && atesX == copX))) {
    //skor++;
    cop = false;
    ates = false;
  }
  if (beklet == false) {
    if (meteor == true && ymeteor == y && xmeteor == x) {
      can--;
      if (can == 2)
        digitalWrite(led1, LOW);
      if (can == 1)
        digitalWrite(led2, LOW);
      if (can == 0)
        digitalWrite(led3, LOW);
      meteor = false;
      beklet = true;
      if (engelmillesbool == false) {
        engelmillesilk = millis();
        engelmillesbool = true;
      }
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
    }
  }
  if (beklet == false) {
    if (cop == true && copY == y && copX == x) {
      can--;
      if (can == 2)
        digitalWrite(led1, LOW);
      if (can == 1)
        digitalWrite(led2, LOW);
      if (can == 0)
        digitalWrite(led3, LOW);
      cop = false;
      beklet = true;
      if (engelmillesbool == false) {
        engelmillesilk = millis();
        engelmillesbool = true;
      }
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
    }
  }
  if (engelmillesbool == true) {
    engelmillesson = millis();
    if ((engelmillesson - engelmillesilk) > 3000) {
      engelmillesbool = false;
      beklet = false;
    }
  }
  if (can == 0) {
    bitis = 0;
  }
  ymeteor--;
  copY--;
  if (odul == true) {
    odulY--;
  }
  if (ates == true) {
    atesY++;
  }
  if (dokunulmaz == true) {
    dokunulmazY--;
  }
  if (ymeteor < 0) {
    meteor = false;
  }
  if (copY < 0) {
    cop = false;
  }
  if (odulY < 0) {
    odul = false;
  }
  if (dokunulmazY < 0) {
    dokunulmaz = false;
  }
  if (atesY > 15) {
    ates = false;
  }
  if (bitis == 0) {
    menuu = true;
  }
  dokunulmazsure++;
  odulsure++;
  display.display();
  gamemillesson = millis();
  platformsure = gamemillesson - menumilles;
  if (hizlanma == true && platformsure >= 10000 * sayachizlanma) {
    sayachizlanma++;
    whilehiz = whilehiz-(whilehiz * 0.2);
  }
  while(whilemillis==0){
    gamemillesson = millis();
    gamemillesson = gamemillesson - (gamemillesilk);    
    if(gamemillesson>=whilehiz){
      whilemillis = 1;
    }
  }
}
void MATRIS(void) {
    if(matris == false){
      oyunMatris[x][y] = 1;
      matris = true;
    }
  unsigned long millees = millis();
  millees = abs(millees);
  millees = millees - menumilles;
  if (millees > 1000 * yenimeteorolusturmasayisi) {
    do {
      meteoryeniX = random(8);
      meteoryeniY = 15;
    } while ((copX == meteoryeniX && copY == meteoryeniY) || (copX + 1 == meteoryeniX && copY == meteoryeniY) || (copX - 1 == meteoryeniX && copY == meteoryeniY) ||(xmeteor == meteoryeniX && ymeteor == meteoryeniY) || (xmeteor + 1 == meteoryeniX && ymeteor == meteoryeniY) || (xmeteor - 1 == meteoryeniX && ymeteor == meteoryeniY) || (dokunulmazX == meteoryeniX && dokunulmazY == meteoryeniY) || (dokunulmazX + 1 == meteoryeniX && dokunulmazY == meteoryeniY) || (dokunulmazX - 1 == meteoryeniX && dokunulmazY == meteoryeniY) || (odulX == meteoryeniX && odulY == meteoryeniY) || (odulX + 1 == meteoryeniX && odulY == meteoryeniY) || (odulX - 1 == meteoryeniX && odulY == meteoryeniY));
    sayac++;
    yenimeteorolusturmasayisi++;
    oyunMatris[meteoryeniX][meteoryeniY] = 2;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 16; j++) {
      if (oyunMatris[i][j] == 2) {
        if (ates == true && ((atesY + 1 == j && atesX == i) || (atesY == j && atesX == i) || (atesY - 1 == j && atesX == i))) {
          ates = false;
          sil = true;
        }
        if (beklet == false) {
          if (i==x && j==y) {
            can--;
            if (can == 2)
              digitalWrite(led1, LOW);
            if (can == 1)
              digitalWrite(led2, LOW);
            if (can == 0)
              digitalWrite(led3, LOW);
            beklet = true;
            sil = true;
            if (engelmillesbool == false) {
              engelmillesilk = millis();
              engelmillesbool = true;
            }
            tone(buzzer, 1000);
            delay(50);
            noTone(buzzer);
          }
        }
        if (j == 0 || sil == true) {
          oyunMatris[i][j] = 0;
        }
        if (j != 0 && sil == false) {
          oyunMatris[i][j - 1] = 2;
          oyunMatris[i][j] = 0;
        }
        if (a1 == true)
          display.drawBitmap(j * 8, i * 8, nmeteor, 8, 8, 1);
        if (a2 == true)
          display.drawBitmap(j * 8, i * 8, nmeteor, 8, 8, 0); 
        sil = false;
      }
    }
  }
}
void anaMenu(void) {
  int down = digitalRead(17);
  int up = digitalRead(18);
  int enter = digitalRead(16);
  int back = digitalRead(15);
  if (selected == 0) {
    if (up == 0) {
      selected = selected + 1;
      delay(200);
    };
  }
  if (selected == 1) {
    if (down == 0) {
      selected = selected - 1;
      delay(200);
    };
  }
  if (enter == 0) {
    entered = selected;
    delay(100);
  };
  if (back == 0) {
    entered = -1;
    delay(100);
  };
  const char *options[2] = {
    " BASLA ",
    " SEVIYE "
  };
  if (entered == -1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setRotation(1);
    display.println(F("<<<Menu>>>"));
    display.println("");
    for (int i = 0; i < 2; i++) {
      if (i == selected) {
        display.setTextColor(BLACK, WHITE);
        display.println(options[i]);
      } else if (i != selected) {
        display.setTextColor(WHITE);
        display.println(options[i]);
      }
    }
  } else if (entered == 0) {
    display.setRotation(4);
    if (menumillesbool == false) {
      menumilles = millis();
      menumillesbool = true;
    }
    Game();
  } else if (entered == 1) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.println("OYUN HIZLANACAKTIR");
    hizlanma = true;
  }
  display.display();
}
void setup() {
  Serial.begin(9600);
  pinMode(basButon, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(silahled1, OUTPUT);
  pinMode(silahled2, OUTPUT);
  pinMode(silahled3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(displayA, OUTPUT);
  pinMode(displayB, OUTPUT);
  pinMode(displayC, OUTPUT);
  pinMode(displayD, OUTPUT);
  pinMode(displayE, OUTPUT);
  pinMode(displayF, OUTPUT);
  pinMode(displayG, OUTPUT);
  pinMode(displayA1, OUTPUT);
  pinMode(displayB1, OUTPUT);
  pinMode(displayC1, OUTPUT);
  pinMode(displayD1, OUTPUT);
  pinMode(displayE1, OUTPUT);
  pinMode(displayF1, OUTPUT);
  pinMode(displayG1, OUTPUT);
  pinMode(displayA2, OUTPUT);
  pinMode(displayB2, OUTPUT);
  pinMode(displayC2, OUTPUT);
  pinMode(displayD2, OUTPUT);
  pinMode(displayE2, OUTPUT);
  pinMode(displayF2, OUTPUT);
  pinMode(displayG2, OUTPUT);
  displaygosterim(0);
  displaygosterim1(0);
  displaygosterim2(0);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
}
void loop() {
  if(menuu == true){
    menusifirlamalari();
  }
  anaMenu();
}