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

int state;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(L298N_ENA, OUTPUT);
  pinMode(L298N_ENB, OUTPUT);
  pinMode(L298N_IN1, OUTPUT);
  pinMode(L298N_IN2, OUTPUT);
  pinMode(L298N_IN3, OUTPUT);
  pinMode(L298N_IN4, OUTPUT);
}

void robotForward(int robotSpeed)
{
  analogWrite(L298N_ENA, robotSpeed);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, HIGH);

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
  if (digitalRead(BUTTON) == LOW) {
    delay(200);
    if(state==5){
      state = 0;
    }
    else{
      state++;
    }
  }
  else {
    switch (state) {
      case 0:
      robotStop();
      Serial.println(state);
      break;
      case 1:
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
      default:
      robotStop();
      Serial.println(state);
      break;
    }
  }
}
