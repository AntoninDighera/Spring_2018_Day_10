//TempDinoEvent 
#include <SoftwareSerial.h>
#include <Servo.h>

//General 
int retDelay = 1000;
int minPos = 30;  
int maxPos = 150; 
int delayTime = 100;

//Team 1
Servo comet;
Servo explosion;

int cometServPin = 3;
int explosionServPin = 5; 


//Team 2 


//Team 3 

Servo roar;
Servo moveExplosion;

const int roarPin = 6;
const int moveExplosionPin = 9;
int revTime = 1000;

void setup(){ 
  //Team 1
  // function from setup
  explosion.attach(explosionServPin);
  comet.attach(cometServPin);
  
  //Team 2 
  
  //Team 3 
  roar.attach(roarPin);
  moveExplosion.attach(moveExplosionPin);
}

void loop () {
  //General 
  
  //Team 1 
  
  moveCometDown();
  bigAfExplosionUp();
  delay(2000);
  moveCometUp();
  bigAfExplosionDown();
  
  
  //Team 2 
  
  //Team 3 
  MoveExplosion();
  Roar();
}


//Functions 


//Team 1 

void moveCometDown() {
  int incrementComet;
  int incrementExplosion;

  int delayTime = 30;

  int retDelay = 5000;
  int minPos = 30;
  int maxPos = 150;

  
  int pos = minPos;
  incrementComet = 10;
  if (incrementComet > 0) {
    while (pos < maxPos) {
      pos += incrementComet;
      comet.write(pos);
      delay(delayTime);
    }
    incrementComet = -5;
  }
}

void moveCometUp() {
  comet.write(90);
  delay(7000);
  comet.write(20);
  delay(7000);
  comet.write(90);
  /*
  int incrementComet;
  int incrementExplosion;

  int delayTime = 30;

  int retDelay = 5000;
  int minPos = 30;
  int maxPos = 150;
  int cometServPin = 2;

  
  comet.attach(cometServPin);
  
  int pos = maxPos;
  incrementComet = -5;
  if (incrementComet < 0) {
    while (pos > minPos) {
      pos += incrementComet;
      comet.write(pos);
      delay(delayTime);
    }
    incrementComet = 10;  
  }
  */
}


void bigAfExplosionUp() {
  comet.write(90);
  delay(7000);
  comet.write(160);
  delay(7000);
  comet.write(90);
  /*
  //declaring variables
  int incrementExplosion;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 160;
  int explosionServPin = 1; 
  
  // function from setup
  explosion.attach(explosionServPin);

  //actual code
  int pos = minPos;
  incrementExplosion = 3;
  if (incrementExplosion > 0) {
    while (pos < maxPos) {
      pos += incrementExplosion;  
      explosion.write(pos);
      delay(delayTime);
    }
    incrementExplosion = -6;  
  }
  delay(retDelay);
  */
}

void bigAfExplosionDown() { 
  // declaring variables
  int incrementExplosion;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 160;

  


  //actual code
  int pos = maxPos;
  incrementExplosion = -6;
  if (incrementExplosion < 0) {
    while (pos > minPos) {
      pos += incrementExplosion;  
      explosion.write(pos);
      delay(delayTime);
    }
    incrementExplosion = 3;  
  }
  delay(retDelay);
}


//Team 2 


//Team 3 
void Roar()
{
  int roarMinPos = 0;
  int roarMaxPos = 45;
  int roarDelayTime = 100;
  for(int i = minPos; i <= maxPos; i += 2)
  {
    roar.write(i);
    delay(roarDelayTime);
  }
  
  for(int i = roarMaxPos; i >= roarMinPos; i -= 2)
  {
    roar.write(i);
    delay(roarDelayTime);
  }
  delay(revTime); 
}

void MoveExplosion()
{
  int explosionMin = 30;
  int explosionMax = 150;
  int moveExplosionDelayTime = 25;
  for(int i = explosionMin; i <= explosionMax; i++) 
  {
    moveExplosion.write(i);
    delay(moveExplosionDelayTime);
  }
  
  for(int i = explosionMax; i >= explosionMin; i--)
  {
    moveExplosion.write(i);
    delay(moveExplosionDelayTime);
  }
  delay(revTime);
}
