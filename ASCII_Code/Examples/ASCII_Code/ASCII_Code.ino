#include"ASCII_Code.h";
ASCII_Code ac;
void setup() {
Serial.begin(9600);
}

void loop() {
//ac.Convert_ASCII(B01010010);// TYPE R in binary to char
ac.Convert_ASCII(0x52);// TYPE R in hex to char
Serial.println(ac.ASCII_Return());
}
