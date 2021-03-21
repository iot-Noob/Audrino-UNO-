#include<flasher.h>
flasher f1(4,5,6);
void setup() {
f1.PinSetup();
}

void loop() {
f1.Sequance1();
}
