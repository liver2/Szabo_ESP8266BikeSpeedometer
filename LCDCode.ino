#include <LiquidCrystal_I2C.h>

int reedPin = 2;
int time = 0;
double velocity = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(reedPin,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void lcdPrint(String s) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s);
  lcd.print(" mph");
}

void lcdPrint(int s) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(s);
  lcd.print(" mph");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(reedPin) == 0)
  {
    time = 0;
    while(1)
    {
      delay(50);
      time += 50; 
      if (digitalRead(reedPin) == 0)
      {
        break;
      }
    }

    velocity = (int) (4997/((double) time));

    if (time != 50)
    {
      lcdPrint(velocity);
    }  
  }
  delay(50);
}
