/*


  The circuit:
 * LCD RS pin to digital pin 6
 * LCD Enable pin to digital pin 7
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
#include"battery.h"

battery b1(A0);
void setup() {
  b1.begin(11,1);
//b1.batvolt(7.0);
}

void loop() {
 b1.Main();
}
