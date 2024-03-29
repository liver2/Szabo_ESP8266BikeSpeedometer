# ESP8266 Bike Speedometer

**Situation:** Wanted to measure the speed of my bicycle without GPS functionality (due to potential inaccuracy).

**Process:** Calculated a conversion from revolutions per second for a 28 in. bike to miles per hour (*InitialCalculation.jpeg*). Brainstormed and landed on magnetically operated mechanism to trigger a revolution (*SchematicsAndDesign.jpeg*). Tested design on a mockup bicycle and an Arduino Uno (*LCDCode.ino*). Designed and built circuit on actual bicycle, modified code for ESP8266, and designed battery holder (*ESPCode.ino*).

**Result:** Outputs accurate and timely results for the speed of the bicycle.
