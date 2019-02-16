/*
 * Author : Hank
 * Instructions:
 * 1) Upload the code
 * 2) Press the button on the Maker Uno (the one below the reset button) and observe the motor spinning
*/
#define BUTTON    2
#define L298N_ENA 5
#define L298N_ENB 6
#define L298N_IN1 7
#define L298N_IN2 9
#define L298N_IN3 10
#define L298N_IN4 11

int state; //state of the robot, moving, reverse,turn left,turn right etc

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);   //enable the button at pin 2 (only works for pin 2)
  pinMode(L298N_ENA, OUTPUT);
  pinMode(L298N_ENB, OUTPUT);
  pinMode(L298N_IN1, OUTPUT);
  pinMode(L298N_IN2, OUTPUT);
  pinMode(L298N_IN3, OUTPUT);
  pinMode(L298N_IN4, OUTPUT);
}

/*
Makes the robot move forward with motor driver as the head of direction
*/
void robotForward(int robotSpeed)
{
  analogWrite(L298N_ENA, robotSpeed); //To change speed on one of the motors
  digitalWrite(L298N_IN1, LOW);       //To change direction on one of the motors
  digitalWrite(L298N_IN2, HIGH);      //To change direction on one of the motors as well, IN1 and IN2 are relative to each other

  analogWrite(L298N_ENB, robotSpeed);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, LOW);
}

void robotReverse(int robotSpeed)
{
  analogWrite(L298N_ENA, robotSpeed);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, LOW);

  analogWrite(L298N_ENB, robotSpeed);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, HIGH);
}

void robotTurnLeft(int robotSpeed)
{
  analogWrite(L298N_ENA, robotSpeed);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, LOW);

  analogWrite(L298N_ENB, robotSpeed);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, LOW);
}

void robotTurnRight(int robotSpeed)
{
  analogWrite(L298N_ENA, robotSpeed);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, HIGH);

  analogWrite(L298N_ENB, robotSpeed);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, HIGH);
}

void robotStop()
{
  digitalWrite(L298N_ENA, LOW);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, LOW);

  digitalWrite(L298N_ENB, LOW);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, LOW);
}

void robotBrake()
{
  digitalWrite(L298N_ENA, HIGH);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, HIGH);

  digitalWrite(L298N_ENB, HIGH);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, HIGH);
}

void loop()
{
  if (digitalRead(BUTTON) == LOW) {   //when button is pressed, 0v signal is sent
    delay(200);					      //a delay is added to avoid unnessary repeating signals when button is pressed as it is mechanical switch, also known as signal bouncing.
    if(state==5){                     //reset 
      state = 0;
    }
    else{
      state++;						  //increment by 1
    }
  }
  else {
    switch (state) {                  //another method instead of writing if else statements, cases look more tidy
      case 0:                         //if state == 0
      robotStop();
      Serial.println(state);
      break;
      case 1:						  //if state == 1
      robotForward(200);
      Serial.println(state);
      break;
      case 2:
      robotReverse(200);
      Serial.println(state);
      break;
      case 3:
      robotTurnRight(200);
      Serial.println(state);
      break;
      case 4:
      robotTurnLeft(200);
      Serial.println(state);
      break;
      case 5:
      robotBrake();
      Serial.println(state);
      break;
      default:                        //if state is neither of the values 1 to 5
      robotStop();
      Serial.println(state);
      break;
    }
  }
}
