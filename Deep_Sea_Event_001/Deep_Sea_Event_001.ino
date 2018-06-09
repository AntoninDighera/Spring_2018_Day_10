//Deep Sea Event 

#include <SoftwareSerial.h>
#include <Servo.h>


//General 
int retDelay = 1000;
int minPos = 30;  
int maxPos = 150; 
int delayTime = 100;


//Team 4 Servos
Servo TreasureOpen;
Servo AnglerBite;
 
//Team 5 Servos
Servo jellyfish1;
Servo sharkJaw;

//Team 6 Servos
Servo Volcano;

//Team 4 pins
int treasurePin = 5;
int anglerPin = 6;
 
//Team 5 pins
int JellyFishServoPin = 10;
int sharkJawServoPin = 9;

//Team 6 pins
int VolcanoPin= 11;


//Team 4 Global Vars
 
//Team 5 Global Vars

//Team 6 Global Vars

void setup() { 
  //General 

  //Team 4
  TreasureOpen.attach(treasurePin);
  AnglerBite.attach(anglerPin);
  
  //Team 5
  moveJellyFishSetupFunction();
  sharkJawSetupFunction();
  
  //Team 6
}




void loop () { 
  //Team 4 
  moveTreasureOpen();
  delay(retDelay);
  
  moveAnglerBite();
  delay(retDelay);
  
  //Team 5 
  moveJellyFishFunction();
  sharkJawFunction();
  
  //Team 6
  VolcanoUp();
  VolcanoDown();
}

// Team 4
//
//
void moveTreasureOpen() 
{
  int i = 1;    //counter
  int delayTimeTreasureOpen = 50;  //Delay to allow gears to do things 
  int retDelayTreasureOpen = 100;
  int minPosTreasureOpen = 30;      //30 degrees or it dies 
  int maxPosTreasureOpen = 150;     //150 degrees or it DIES
  for (int pos = minPosTreasureOpen; pos < maxPosTreasureOpen; pos += i) 
  {
    //Do THING
    TreasureOpen.write(pos);
    delay(delayTime);
  }
}

void moveAnglerBite() 
{
  int i = 3;    //counter
  int delayTimeAnglerBite = 50;  //Delay to allow gears to do things 
  int retDelayAnglerBite = 100;
  int minPosAnglerBite = 80;      //30 degrees or it dies 
  int maxPosAnglerBite = 120;     //150 degrees or it DIES
  for (int pos = minPos; pos < maxPos; pos += i)
  {
    //Do THING
    AnglerBite.write(pos);
    delay(delayTime);
  }
}


// Team 5 
//
//
//shark jaw moving, event based
 void sharkJawSetupFunction () {
  int sharkDelayTime = 50;
  int sharkRetDelay = 1000;
  int sharkMinPos = 30;
  int sharkMaxPos = 150;
  int sharkIncrement = 1;
  sharkJaw.attach(sharkJawServoPin);
 }
  void sharkJawFunction (){
   for(int pos = 30; pos < 150; pos ++) {
    sharkJaw.write(pos);
    delay(50);
  }
 }

//Jellyfish moving event based
 void moveJellyFishSetupFunction (){
  int jellyFDelayTime = 500;
  int jellyFRetDelay = 1000;
  int jelyFMinPos = 30;
  int jellyFMaxPos = 150;
  int jellyFIncrement = 1;
  jellyfish1.attach(JellyFishServoPin);
}
void moveJellyFishFunction (){
  jellyfish1.write(30); 
  delay(500);
  jellyfish1.write(150);
  delay(500);
  delay(100);
}



// Team 6
//
//
void VolcanoUp() {
  int increment;
  int minPos = 30;
  int maxPos = 150;
  int delayTime = 30;
  int retDelay = 1000;
  int pos = minPos + 20;
  increment = 3;
  if (increment > 0) {
    while (pos < maxPos - 30) {
      pos += increment;
      Volcano.write(pos);
      delay(delayTime);
    }
    increment = -3;
  }
  delay(retDelay);
}

void VolcanoDown() {
  int increment;
  int minPos = 30;
  int maxPos = 150;
  int delayTime = 30;
  int retDelay = 1000;
  int pos = maxPos - 20;
  increment = -3;
  if (increment < 0) {
    while (pos > minPos + 20) {
      pos += increment;
      Volcano.write(pos);
      delay(delayTime);
    }
  increment = 3;
  }
 delay (retDelay);
}

