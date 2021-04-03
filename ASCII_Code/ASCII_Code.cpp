#include"ASCII_Code.h";
#include"Arduino.h"

ASCII_Code::ASCII_Code() {
Serial.begin(9600);  
}

void ASCII_Code:: Convert_ASCII(int a) {
in=a;
out= ((char)in);

}

char ASCII_Code::ASCII_Return() {
 return out= ((char)in); 
}
