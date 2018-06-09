//Temp Deep Sea Cont 

#include <SoftwareSerial.h>
#include <Servo.h>


//General 
int retDelay = 1000;
int minPos = 30;  
int maxPos = 150; 
int delayTime = 100;


//Team 4
Servo SubUpAndDown;
Servo SquidOrbit;
Servo BubblesMove;

int i = 1;    //counter

int submarinePin = 10;      //Pin it's hooked up to on Arduino 
int squidPin = 9;
int bubblesPin = 7;
 
//Team 5
Servo dolphinTail;
Servo diver;
Servo jellyFishLights;

int diverServoPin = 12;
int dolphinServoPin = 11;
int red = 11;
int green = 10;
int blue = 6; 

//Team 6
Servo Dolphin;
Servo Turtle;
Servo Seaweed;

int DolphinPin = 3;
int TurtlePin = 6;
int SeaweedPin = 9;

void setup() { 
  //General 

  //Team 4
  SubUpAndDown.attach(submarinePin);   
  SquidOrbit.attach(squidPin);   
  BubblesMove.attach(bubblesPin);  
  
  //Team 5
  dolphinTailSetupFunction (); 
  jellyFishLightsSetupFunction ();
  diverSetupFunction ();
  
  //Team 6
  Dolphin.attach(DolphinPin);
  Turtle.attach(TurtlePin);
  Seaweed.attach(SeaweedPin);
}




void loop () { 
  //Team 4 
  moveSubmarine();
  delay(retDelay);
  
  moveSquid();
  delay(retDelay);
  
  moveBubbles();
  delay(retDelay);
  
  //Team 5 
  dolphinTailFunction (); 
  jellyFishLightsFunction ();
  diverFunction ();
  
  //Team 6
  moveDolphin();
  moveTurtle();

}

// Team 4
//
//
void moveSubmarine() 
{
  int i = 1;    //counter
  int delayTimeSubmarine = 50;  //Delay to allow gears to do things 
  int retDelaySubmarine = 10;
  int minPosSubmarine= 30;      //30 degrees or it dies 
  int maxPosSubmarine = 150;     //150 degrees or it DIES
  for (int pos = minPosSubmarine; pos < maxPosSubmarine; pos += i)
  {
    //Do THING
    SubUpAndDown.write(pos);
    delay(delayTime);
  }
}

void moveSquid() 
{
  int i = 1;    //counter
  int delayTimeSquid = 50;  //Delay to allow gears to do things 
  int retDelaySquid = 10;
  int minPosSquid = 30;      //30 degrees or it dies 
  int maxPosSquid = 150;     //150 degrees or it DIES
  for (int pos = minPosSquid; pos < maxPosSquid; pos += i)
  {
    //Do THING
    SquidOrbit.write(pos);
    delay(delayTime);
  }
}

void moveBubbles() 
{
  int i = 1;    //counter
  int delayTimeBubbles = 50;  //Delay to allow gears to do things                                                                                                                                                                                                                         
  int retDelayBubbles= 10;
  int minPosBubbles= 30;      //30 degrees or it dies 
  int maxPosBubbles = 150;     //150 degrees or it DIES
  for (int pos = minPosBubbles; pos < maxPosBubbles; pos += i)
  // int pos = 30 degree; as long as position less than 150; pos + 1
  
  {
    //Do THING
    BubblesMove.write(pos);
    delay(delayTime);
  }

} 


// Team 5 
//
//

//dolphin tail moving
void dolphinTailSetupFunction () { 
  int dolphinTDelayTime = 100;
  int dolphinTRetDelay = 1000;
  int dolphinTMinPos = 30;
  int dolphinTMaxPos = 150;
  int dolphinTIncrement = 1; 
  dolphinTail.attach(dolphinServoPin);
  }
  
void dolphinTailFunction () {
  dolphinTail.write(30);
  delay(500);
  dolphinTail.write(150);
  delay(500);
}

//diver
void diverSetupFunction (){
 int delayTime = 500;
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 150;
  int increment = 1;
  diver.attach(diverServoPin);
}
 void diverFunction () {
  diver.write(30); 
  delay(500);
  diver.write(150);
  delay(500);
  
 }

//jellyfish lights
void jellyFishLightsSetupFunction () {
  pinMode(red,OUTPUT); 
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT); 
}
void jellyFishLightsFunction (){
  analogWrite (red, HIGH); 
  analogWrite (green, LOW);
  analogWrite (blue, LOW);
    
  delay(200);

  analogWrite (red, HIGH); 
  analogWrite (green, LOW);
  analogWrite (blue, HIGH);
    
  delay(200);

  analogWrite (red, LOW); 
  analogWrite (green, HIGH);
  analogWrite (blue, HIGH);
  delay(200);
}



// Team 6
//
//
void moveDolphin() {
  int increment = 1;
  int minPos = 10;
  int maxPos = 100;
  int delayTime = 10;
  for (int pos = minPos; pos < maxPos; pos += increment) {
   //pos > maxPos; pos -= increment
  Serial.print("dolphin");
  Dolphin.write(pos);
  delay(delayTime);
  //int pos = minPos;
  }
}

void moveTurtle() {
  int increment = 1;
  int minPos = 30;
  int maxPos = 80;
  int delayTime = 20;
  for (int pos = minPos; pos < maxPos; pos += increment) {
   //pos > maxPos; pos -= increment
  Serial.print("turtle");
  Turtle.write(pos);
  delay(delayTime);
  //int pos = minPos;
  }
}
  
void moveSeaweed() {
  int increment = 1;
  int minPos = 30;
  int maxPos = 80;
  int delayTime = 20;
  for (int pos = minPos; pos < maxPos; pos += increment) {
   //pos > maxPos; pos -= increment
  Serial.print("seaweed");
  Seaweed.write(pos);
  delay(delayTime);
  //int pos = minPos;
  }
}


