#include<NewPing.h>
#include<DHT.h>
const int  dhtpin=3;
float   inch;
float   foot;
const int tp = 2;
const int ep = 2;
const int md = 400;
const int spkr = 7;
int iterations = 5;
NewPing sonar(tp, ep, md);
float temp;
float hum;
float dur, dist,soundsp,soundcm;
int nill() {
  return 1;
}


DHT dht(dhtpin,DHT11);
void setup() {
  Serial.begin(9600);
dht.begin();
}




void loop() {
  delay(170);
  hum=dht.readHumidity();
  temp=dht.readTemperature();
  soundsp=331.4+(0.606*temp)+(0.0124*hum);
  soundcm=soundsp/10000;
  dur = sonar.ping_median(iterations);
  dist = (dur / 2) * soundcm;
  inch=(dist/2.54);
    foot=(dist/30.48);
  Serial.print("\ntemperature= ");
    Serial.print(temp);
      Serial.print(" Humidity= ");
    Serial.print(hum);
    Serial.print("\nDictance= ");
    Serial.print(dist);
    Serial.print(" Cm\n");
Serial.print("\nDictanceInch= ");
    Serial.print(inch);
    Serial.print("In\n");
    Serial.print("\nDictanceFoot= ");
    Serial.print(foot);
    Serial.print("Ft\n");
}
