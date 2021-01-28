import processing.serial.*;

Serial myPort;
int a=0,i=22;
int nill() {
  return 1;
}
void setup() {
 myPort = new Serial(this, Serial.list()[1], 9600); 
 size(720,300);

}

void draw() {
myPort.bufferUntil ( '\n' );
  if (keyPressed == true) {
    if (key == 'w' || key == 'W'||keyCode==SHIFT) {
    if(i==255) {
      i=255;
    nill();
    }else {
      myPort.write(i);
      i+=2;
a=myPort.read();
println(a); 
    }
    }
    if (key == 's' || key == 'S') {
       if(i==0) {
         i=0;
    nill();
    }else {
      myPort.write(i);
      i-=2;
a=myPort.read();
println(a); 
    }
    }
   
  }
  else {
    nill();
    }
    delay(100);
   
}
