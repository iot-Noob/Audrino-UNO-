import controlP5.*;
import processing.serial.*;
Serial myPort;
ControlP5 cp5;

int myColorBackground = color(0,0,0);
int knobValue = 100;

Knob myKnobA;
Knob myKnobB;

void setup() {
   myPort = new Serial(this, Serial.list()[1], 9600);
  size(700,400);
  smooth();
  noStroke();

  cp5 = new ControlP5(this);

  myKnobA = cp5.addKnob("knob")
               .setRange(0,255)
               .setValue(50)
               .setPosition(100,70)
               .setRadius(50)
               .setDragDirection(Knob.VERTICAL)
               ;
            

  myKnobB = cp5.addKnob("knobValue")
               .setRange(0,255)
               .setValue(220)
               .setPosition(100,210)
               .setRadius(50)
               .setNumberOfTickMarks(3)
               .setTickMarkLength(4)
               .snapToTickMarks(true)
               .setColorForeground(color(255))
               .setColorBackground(color(0, 160, 100))
               .setColorActive(color(255,255,0))
               .setDragDirection(Knob.HORIZONTAL)
               ;
}

void draw() {
  background(myColorBackground);
  fill(knobValue);
  rect(0,height/2,width,height/2);
  fill(0,100);
  rect(80,40,140,320);
    
}

int v,gsv;
void knob(int theValue) {
  myColorBackground = color(theValue);
  println("a knob event. setting background to "+theValue);

  myPort.write(theValue);  
  gsv=myPort.read();
  println(gsv);

  
}

int val;
void keyPressed() {
  switch(key) {
    case('1'):myKnobA.setValue(180);break;
    case('2'):myKnobB.setConstrained(false).hideTickMarks().snapToTickMarks(false);break;
    case('3'):myKnobA.shuffle();myKnobB.shuffle();break;
  
}

}
