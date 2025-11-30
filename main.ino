#define ENA 6
#define IN1 4
#define IN2 5

#define ENB 11
#define IN3 9
#define IN4 10

#define Right_LDR_DO 3
#define Left_LDR_DO 2

const int PWM_SPEED = 180;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Right_LDR_DO, INPUT);
  pinMode(Left_LDR_DO, INPUT);

  Serial.begin(9600);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, PWM_SPEED);
  analogWrite(ENB, PWM_SPEED);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, PWM_SPEED);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENB, PWM_SPEED);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void checkLDR() {
  int R = digitalRead(Right_LDR_DO);
  int L = digitalRead(Left_LDR_DO);

  if (R == 0 && L == 0) forward();
  else if (R == 1 && L == 1) stopMotors();
  else if (R == 0 && L == 1) turnLeft();
  else if (R == 1 && L == 0) turnRight();
}

void loop() {
  checkLDR();
}
