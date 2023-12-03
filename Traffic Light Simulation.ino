#include <LCD_I2C.h>
#include <Wire.h>

// Set the LCD address to 0x27 for a 16x2 display
LCD_I2C lcd1(0x27, 16, 2);
LCD_I2C lcd2(0x26, 16, 2);
LCD_I2C lcd3(0x25, 16, 2);
LCD_I2C lcd4(0x23, 16, 2);

// Define PIN Number
const int LR1 = 1;
const int LY1 = 2;
const int LG1 = 3;
const int LR2 = 4;
const int LY2 = 5;
const int LG2 = 6;
const int LR3 = 7;
const int LY3 = 8;
const int LG3 = 9;
const int LR4 = 10;
const int LY4 = 11;
const int LG4 = 12;
const int BZ = 13;

int looping = 0;

// Define PIN Mode
void setup()
{
  pinMode(LR1, OUTPUT);
  pinMode(LY1, OUTPUT);
  pinMode(LG1, OUTPUT);
  pinMode(LR2, OUTPUT);
  pinMode(LY2, OUTPUT);
  pinMode(LG2, OUTPUT);
  pinMode(LR3, OUTPUT);
  pinMode(LY3, OUTPUT);
  pinMode(LG3, OUTPUT);
  pinMode(LR4, OUTPUT);
  pinMode(LY4, OUTPUT);
  pinMode(LG4, OUTPUT);
  pinMode(BZ, OUTPUT);
  lcd1.begin();
  lcd2.begin();
  lcd3.begin();
  lcd4.begin();
}

void loop()
{
  LEDEAST();
  LEDSOUTH();
  LEDWEST();
  LEDNORTH();
  looping = looping + 1;
 
}

void countdown(int duration, LCD_I2C &lcd)
{
  for (int i = duration; i >= 0; i--)
  {
    lcd.setCursor(0, 1);
    lcd.print("Waktu: ");
    lcd.print(i);
    delay(1000); // Tunggu 1 detik
    // lcd.clear(); // Hapus tampilan waktu setelah satu detik
  }
}


void LEDEAST()
{
  // Ini lampu merah
  digitalWrite(LG1, HIGH);
  digitalWrite(LR2, HIGH);
  digitalWrite(LR3, HIGH);
  digitalWrite(LR4, HIGH);
  lcd1.print("Lampu Hijau");
  countdown(3, lcd1); // Countdown for 3 seconds
  // Ini lampu kuning
  digitalWrite(LG1, LOW);
  digitalWrite(LY1, HIGH);
  digitalWrite(LY2, HIGH);
  digitalWrite(LR2, LOW);
  lcd1.clear();

  digitalWrite(BZ, HIGH);
  lcd1.print("Lampu Kuning");
  countdown(1, lcd1); // Countdown for 1 second
  
  digitalWrite(LY1, LOW);
  digitalWrite(LY2, LOW);
  digitalWrite(BZ, LOW);
  // delay(100);
  lcd1.clear();

  digitalWrite(LR1, HIGH);
  digitalWrite(LG2, HIGH); // Turn on green light on the next LCD (lcd2)
  lcd1.print("Lampu Merah");
  countdown(3, lcd1);
  // // delay(500);
  lcd1.clear();
}

void LEDSOUTH()
{
  digitalWrite(LG2, HIGH);
  digitalWrite(LR2, LOW);
  digitalWrite(LR3, HIGH);
  digitalWrite(LR4, HIGH);
  lcd2.print("Lampu Hijau");
  countdown(3, lcd2);

  
  digitalWrite(LG2, LOW);
  digitalWrite(LY2, HIGH);
  digitalWrite(LY3, HIGH);
  digitalWrite(LR3, LOW);
  lcd2.clear();

  digitalWrite(BZ, HIGH);
  lcd2.print("Lampu Kuning");
  countdown(1, lcd2);

  digitalWrite(LY3, LOW);
  digitalWrite(LY2, LOW);
  digitalWrite(BZ, LOW);
  // delay(100);
  lcd2.clear();
  
  digitalWrite(LR2, HIGH);
  digitalWrite(LG3, HIGH);
  lcd2.print("Lampu Merah");
  countdown(3, lcd2);
  // delay(500);
  lcd2.clear();
}

void LEDWEST()
{
  digitalWrite(LG3, HIGH);
  digitalWrite(LR1, HIGH);
  digitalWrite(LR3, LOW);
  digitalWrite(LR4, HIGH);
  
  lcd3.print("Lampu Hijau");
  countdown(3, lcd3);

  digitalWrite(LG3, LOW);
  digitalWrite(LY3, HIGH);
  digitalWrite(LY4, HIGH);
  digitalWrite(LR4, LOW);
  lcd3.clear();
  
  digitalWrite(BZ, HIGH);
  lcd3.print("Lampu Kuning");
  countdown(1, lcd3);

  digitalWrite(LY3, LOW);
  digitalWrite(LY4, LOW);
  digitalWrite(BZ, LOW);
  // delay(100);
  lcd3.clear();
  
  digitalWrite(LR3, HIGH);
  digitalWrite(LG4, HIGH);
  lcd3.print("Lampu Merah");
  countdown(3, lcd3);
  // delay(500);
  lcd3.clear();
}

void LEDNORTH()
{
  digitalWrite(LG4, HIGH);
  digitalWrite(LR1, HIGH);
  digitalWrite(LR2, HIGH);
  digitalWrite(LR3, HIGH);
  digitalWrite(LR4, LOW);
  
  lcd4.print("Lampu Hijau");
  countdown(3, lcd4);

  digitalWrite(LG4, LOW);
  digitalWrite(LY4, HIGH);
  digitalWrite(LY1, HIGH);
  digitalWrite(LR1, LOW);
  lcd4.clear();
  
  digitalWrite(BZ, HIGH);
  lcd4.print("Lampu Kuning");
  countdown(1, lcd4);

  digitalWrite(LY4, LOW);
  digitalWrite(LY1, LOW);
  digitalWrite(BZ, LOW);
  // delay(100);
  lcd4.clear();

  digitalWrite(LR4, HIGH);
  digitalWrite(LG1, HIGH);
  lcd4.print("Lampu Merah");
  countdown(3, lcd4);
  // delay(500);
  lcd4.clear();
}
