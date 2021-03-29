#include"Arduino.h"
#include "factory.h"
#include <PCM.h>
void factory::alarm() {
  startPlayback(sample,sizeof(sample));
}
void factory::play_alarm() {
 alarm();
delay(650);
}
