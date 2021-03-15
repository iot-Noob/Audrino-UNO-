import processing.serial.*;
import java.awt.Robot;
 import java.awt.event.KeyEvent;
 import java.awt.AWTException;
 import java.awt.*;
import java.awt.event.*;
Serial myPort;
Robot rbt;

int sensivity=54;
void setup() {
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[1], 9600);
    try {
    rbt = new Robot();
  } catch(Exception e) {
    e.printStackTrace();
  }
}

int   ud=0,lr=0;

void draw() {
 
  while (myPort.available() > 0) {
 
int kstroke = myPort.read();
 //println(kstroke);

 
    switch (kstroke) {
      case 117: //up
      ud-=sensivity;
         println("Up/down= ",ud);
           rbt.mouseMove(lr,ud); 
      break;
      
       case 119: //down
      ud+=sensivity;
       println("Up/down= ",ud);
       rbt.mouseMove(lr,ud); 
      break;
      
       case 102: //left
      lr-=sensivity;
       println("Left/right= ",lr);
       rbt.mouseMove(lr,ud); 
      break;
      
       case 104: //right
      lr+=sensivity;
       println("Left/right= ",lr);
       rbt.mouseMove(lr,ud); 
      break;
       case  111:
rbt.mousePress(InputEvent.BUTTON1_DOWN_MASK);
rbt.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
      break;
    }
  } 
}
 
 
