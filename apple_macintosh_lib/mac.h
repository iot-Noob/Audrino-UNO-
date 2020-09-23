#include"melody.h"
int sout;
int notes[7]={f5,a5,c6,f6,a5,as5,fs5};
int Delay[6]={330,330,330,618,280,598};

void mac_startup() {
for(int i=0;i<=6;i++) {
 tone(sout,notes[i],700);
delay(Delay[i]);   
}

}
