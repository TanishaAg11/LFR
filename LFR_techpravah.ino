#define l1 4  //Left Motor MA1
#define l2 7  //Left Motor MA2
#define r1 8  //Right Motor MB1
#define r2 12  //Right Motor MB2
#define e1 3  //Left Motor Enable Pin EA
#define e2 5 //Right Motor Enable Pin EB

//Channel IR Sensor Connection
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4


void setup() {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  //if only middle sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going forward with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left with full speed 
    digitalWrite(e1, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(e2, 50); //you can adjust the speed of the motors from 0-255
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  }

  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //stop
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    delay(120000);
  }
}
