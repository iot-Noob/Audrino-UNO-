#include<SoftwareSerial.h>
#include <StepperControl.h>
 #include <SimpleCLI.h>

SimpleCLI cli;

const int mp[4]={4,5,6,7};

StepperControl control(StepperControl::DefaultStepCount, mp[0],mp[1],mp[2],mp[3]);

SoftwareSerial sserial(2,3);
Command Pos;
Command Speed;
Command Angle;
Command Step;
Command Direction;
Command start;

 
void setup() {
  for(int i=0;i<=3;i++) {
    pinMode(mp[i],OUTPUT);
  }
  Pos=cli.addCmd("Position,pos,rotpos,rotatepos,position");
  Pos.addPosArg("ps");
  Speed=cli.addCmd("speed,rotspeed,ss,stepperspeed");
  Speed.addPosArg("s");
  Angle=cli.addCmd("ra,rotangle,RotAngle");
  Angle.addPosArg("degree");
  Step=cli.addCmd("nos,step");
  Step.addPosArg("fs");
  start=cli.addCmd("start,Start,sm");
  Direction=cli.addCmd("direc,dir,md");
  Direction.addPosArg("d");
 sserial.begin(9600);
 
Serial.begin(9600);
 
}

String rv,temp;
int a,s;

void lmp() {
  for(int i=0;i<=3;i++) {
    digitalWrite(mp[i],LOW);
  }
}

void loop() {

if(sserial.available()>0) {

rv=sserial.readString();
 Serial.print("IoTHacker@Arduino:~$ "+rv);
  cli.parse(rv); 
}

if(cli.available()>0) {
 Command cmd=cli.getCommand(); //clear queue

if(cmd==Pos) {
   Argument argPos=cmd.getArgument("ps");
  temp=argPos.getValue();
  if(temp=="Back"||temp=="back") {
    control.SetDirection(StepperControl::Backward);
  }
    if(temp=="Forward"||temp=="forward") {
    control.SetDirection(StepperControl::Forward);
  }
}

if(cmd==Speed) {
  Argument argSpd=cmd.getArgument("s");
  temp=argSpd.getValue();
   s=temp.toInt();
   control.SetRotationSpeed(s);
}
if(cmd==Angle) {
  Argument argAng=cmd.getArgument("degree");
  temp=argAng.getValue();
  a=temp.toInt();
    const uint32_t steps = control.GetStepsFromDegrees(a);
  control.Step(steps);
   lmp();
}
if(cmd==Step) {
   Argument argAng=cmd.getArgument("fs");
  temp=argAng.getValue(); 
  if(temp=="fs"||temp=="fulstep") {
     control.SetStepType(StepperControl::FullStep);
  }
   if(temp=="hs"||temp=="halfstep") {
     control.SetStepType(StepperControl::HalfStep);
  }
}

if(cmd==Direction) {
  Argument argDir=cmd.getArgument("d");
  temp=argDir.getValue();
  if(temp=="id"||temp=="di") {
    control.SetDirection(control.GetInvertedDirection());
  }
  
}
if(cmd==start) {
 
  }
  
}
 
if(cli.errored()) {
    CommandError e=cli.getError();
    sserial.print("Error");
    delay(18);
    sserial.print(e.toString());
    Serial.println("Error: "+e.toString());
    delay(22);
   }
delay(10);

}
