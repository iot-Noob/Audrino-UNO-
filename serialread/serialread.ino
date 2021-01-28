const int led=3;
void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
}

float sv;

void loop() {
if(Serial.available()>0) {
//sv= Serial.parseInt();
sv=Serial.read();
analogWrite(led,sv);
Serial.println(sv);
}else {

  return 1;
}

}
