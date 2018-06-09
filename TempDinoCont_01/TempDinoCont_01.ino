//Temp Dino Cont 

#include <SoftwareSerial.h>
#include <Servo.h>


//General 
int retDelay = 1000;
int minPos = 30;  
int maxPos = 150; 
int delayTime = 100;


//Team 1
Servo egg;
Servo leaves;
Servo neck;

int incrementEgg;
int incrementLeaves;
int incrementNeck;

const int eggServPin = 3;
//const int leavesServPin = 0; 
const int neckServPin = 5; 
 
//Team 2 

Servo dinofight;
Servo dinofly;
Servo dinodrinks;

//int FightservPin = 11;
int FlyservPin = 6;
int servPin = 9; //drink

int increment = 1;
int Flyincrement = 2;
int Fightincrement = 2;

int FightdelayTime = 1;
int FightretDelay = 30;
int FightminPos = 30;
int FightmaxPos = 1000;

int FlydelayTime = 7;
int FlyretDelay = 3;
int FlyminPos = 30;
int FlymaxPos = 500;




//Team 3
Servo servo2;
Servo servo3;

const int dino_pin = 10;
const int tree_pin = 11;

int Team3DelayTime = 100;





void setup() { 
  //General 

  //Team 1
  egg.attach(eggServPin);
//  leaves.attach(leavesServPin);
  neck.attach(neckServPin);
  
  // Team 2 
//  dinofight.attach(FightservPin);
  dinofly.attach(FlyservPin);
  dinodrinks.attach(servPin);
  
  //Team 3
  servo2.attach(tree_pin);
  servo3.attach(dino_pin);
}




void loop () { 
  //Team 1 
  eggUp();
//  leavesRustleUp();
  eggDown();
//  leavesRustleDown();
  neckForward();
//  leavesRustleUp();
  neckBackward();
//  leavesRustleDown();  
  
/*  //Team 2 
  for (int Fightpos = FightminPos; Fightpos < FightmaxPos; Fightpos += Fightincrement ) {
    dinofight.write(Fightpos);
    delay(FightdelayTime);
  }
*/  
  for (int Flypos = FlyminPos; Flypos < FlymaxPos; Flypos += Flyincrement ) {
    dinofly.write(Flypos);
    delay(FlydelayTime);
  }
  
  for (int pos = minPos; pos < maxPos; pos += increment ) {
    dinodrinks.write(pos);
    delay(delayTime);
  }
  
  //Team 3 
  growTree(); 
  shrinkTree(); 
  runDino(); 
}

// Team 1 
//
//

void eggUp() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 90;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  egg.attach(eggServPin);

  //actual code
  int pos = minPos;
  incrementEgg = 3;
  if (incrementEgg > 0) {
    while (pos < maxPos) {
      pos += incrementEgg;  
      egg.write(pos);
      delay(delayTime);
    }
    incrementEgg = -3;  
  }
  delay(retDelay);
}

void eggDown() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 90;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  egg.attach(eggServPin);

  //actual code
  int pos = maxPos;
  incrementEgg = -3;
  if (incrementEgg < 0) {
    while (pos > minPos) {
      pos += incrementEgg;  
      egg.write(pos);
      delay(delayTime);
    }
    incrementEgg = 3;  
  } 
  delay(retDelay);
}

void leavesRustleUp() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  leaves.attach(leavesServPin);

  //actual code
  int pos = minPos + 50;
  incrementLeaves = 1;
  if (incrementLeaves > 0) {
    while (pos < maxPos - 50) {
      pos += incrementLeaves;  
      leaves.write(pos);
      delay(delayTime);
    }
    incrementLeaves = -1;  
  }
  delay(retDelay);
}

void leavesRustleDown() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  leaves.attach(leavesServPin);

  //actual code
  int pos = maxPos - 50;
  incrementLeaves = -1;
  if (incrementLeaves < 0) {
    while (pos > minPos + 50) {
      pos += incrementLeaves;  
      leaves.write(pos);
      delay(delayTime);
    }
    incrementLeaves = 1;  
  } 
  delay(retDelay);
}

void neckForward() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  neck.attach(neckServPin);

  //actual code
  int pos = minPos + 80;
  incrementNeck = 2;
  if (incrementNeck > 0) {
    while (pos < maxPos) {
      pos += incrementNeck;  
      neck.write(pos);
      delay(delayTime);
    }
    incrementNeck = -2;  
  }
  delay(retDelay);
}

void neckBackward() {
  // declaring variables
  int incrementEgg;
  int incrementLeaves;
  int incrementNeck;
  
  int delayTime = 30;
  
  int retDelay = 1000;
  int minPos = 30;
  int maxPos = 150;
  int eggServPin = 7; 
  int leavesServPin = 9; 
  int neckServPin = 5; 
  
  // function from setup
  neck.attach(neckServPin);

  //actual code
  int pos = maxPos;
  incrementNeck = -2;
  if (incrementNeck < 0) {
    while (pos > minPos + 80) {
      pos += incrementNeck;  
      neck.write(pos);
      delay(delayTime);
    }
    incrementNeck = 2;  
  } 
  delay(retDelay);
}

// Team 2 
//
//


// Team 3
//
//

void growTree()
{
  int delayTime = 100;
  for(int i = 0; i < 3; i++) //3 states total
  {
    int initialPos = servo2.read();
    for(int j = initialPos; j < initialPos + 59; j++) //going +59 degrees per state
    {
      servo2.write(j);
      delay(delayTime);
    }
  }
}

void shrinkTree()
{
  int delayTime = 100;
  for(int i = 3; i > 0; i++)
  {
    int x = servo2.read();
    for(int j = x; j > x - 59; j--)
    {
      servo2.write(j);
      delay(delayTime);
    }
  }
}

void runDino()
{
  int minPos = 0;
  int maxPos = 150;
  int delayTime = 100;
  for (int i=minPos; i<=maxPos;i+=4)
  {
    servo3.write(i);
    delay(delayTime);
  }
  for (int i=minPos; i>=minPos;i-=1)
  {
    servo3.write(i);
    delay(delayTime);
  }
}


