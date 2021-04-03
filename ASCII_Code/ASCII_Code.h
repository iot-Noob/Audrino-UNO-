#ifndef ASCII_Code_h
#define ASCII_Code_h
#include"Arduino.h"

class ASCII_Code {
private:

char out;
int in;

public:  
ASCII_Code();
 
void  Convert_ASCII(int a);

char ASCII_Return();

};

#endif
