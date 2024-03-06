#include <U8g2lib.h> // includes library
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 5, /* data=*/ 4); // establishes u8g display

int reedPin = 10;
int speedTime = 0;
double velocity = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(reedPin,INPUT_PULLUP);
  Serial.begin(9600);
  u8g2.begin();
}

void u8g2Print(int s) {
  u8g2.setFont(u8g2_font_logisoso32_tf);
  u8g2.print(s,0);
  u8g2.drawStr(18,32,"mph");
  u8g2.setCursor(0,32);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(reedPin) == 0)
  {
    speedTime = 0;
    while(1)
    {
      delay(50);
      speedTime += 50;   
      if (digitalRead(reedPin) == 0)
      {
        break;
      }
    }

    velocity = (int) (4997/((double) speedTime));

    if (speedTime != 50)
    {
      u8g2Print(velocity);
    }  
  }
  delay(50);
}
