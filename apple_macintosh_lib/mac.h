#include"melody.h"
int sout;
int notes[7]={f5,a5,c6,f6,a5,as5,fs5};
int Delay[6]={430,430,430,598,280,298};

void mac_startup() {
for(int i=0;i<=6;i++) {
 tone(sout,notes[i],500);
delay(Delay[i]);   
}

}
