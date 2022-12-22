#define direction_Leftmotor_F 4 //for motor 1 & motor 3 forward
#define direction_Leftmotor_B 5 //for motor 1 & motor 3 backward
#define direction_Rightmotor_F 7 //for motor 2 & motor 4 forward
#define direction_Rightmotor_B 8 //for motor 2 & motor 4 backward
#define enableA 3 //speed control for left motor
#define enableB 6 //speed control for right motor


#define channel2 11
#define channel4 10
#define channel5 9

int ch2;
int ch4;
int ch5;


char bt = 'F';
int motor_speed = 230 ;
void setup()
{
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(direction_Leftmotor_F, OUTPUT);
  pinMode(direction_Leftmotor_B, OUTPUT);
  pinMode(direction_Rightmotor_F, OUTPUT);
  pinMode(direction_Rightmotor_B, OUTPUT);

   pinMode(channel2,INPUT);
    pinMode(channel4,INPUT);
     pinMode(channel5,INPUT);
  
}
void loop(){
 ch2 = pulseIn(11, HIGH, 25000); // Read the pulse width of  
//  Serial.print("Channel 2:");
//  Serial.println(ch2);
  delay(10);

  ch4 = pulseIn(10, HIGH, 25000); // Read the pulse width of  
//  Serial.print("Channel 4:");
//  Serial.println(ch4);
  delay(10);

    ch5 = pulseIn(9, HIGH, 25000); // Read the pulse width of  
//  Serial.print("Channel 5:");
//  Serial.println(ch5);
  delay(10);

motor_speed = map(ch5,900,1900,150,240);
delay(1);

int j = ch2;
int k = ch4;

if (j > 1700){
        forward();   
        }
         delay(1);
     if (j <1300){
        backward();
        }
         delay(1);
        if(j > 1300 && j < 1700){
          Stop();
          }
delay(1);
 if(ch4<1300){
      left();
    }
    delay(1);
    if(ch4>1500){
      right();
      }


//  motor_speed = map(ch5,900,1900,150,255);       

  
}
void forward()
{
  Serial.println("forward");
  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, HIGH);
  digitalWrite(direction_Leftmotor_B, LOW);
  digitalWrite(direction_Rightmotor_F, HIGH);
  digitalWrite(direction_Rightmotor_B, LOW);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
  
}
void backward()
{
    Serial.println("backward");

  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, LOW);
  digitalWrite(direction_Leftmotor_B, HIGH);
  digitalWrite(direction_Rightmotor_F, LOW);
  digitalWrite(direction_Rightmotor_B, HIGH);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
}
void right()
{
    Serial.println("right");

  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, HIGH);
  digitalWrite(direction_Leftmotor_B, LOW);
  digitalWrite(direction_Rightmotor_F, LOW);
  digitalWrite(direction_Rightmotor_B, HIGH);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
}
void left()
{
    Serial.println("left");

  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, LOW);
  digitalWrite(direction_Leftmotor_B, HIGH);
  digitalWrite(direction_Rightmotor_F, HIGH);
  digitalWrite(direction_Rightmotor_B, LOW);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
}
 void ForwardLeft()
 {
  int leftmotor_speed = motor_speed * 0.43;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, HIGH);
  digitalWrite(direction_Leftmotor_B, LOW);
  digitalWrite(direction_Rightmotor_F, HIGH);
  digitalWrite(direction_Rightmotor_B, LOW);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
 }
  void Forwardright()
  {
  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed * 0.43;
  digitalWrite(direction_Leftmotor_F, HIGH);
  digitalWrite(direction_Leftmotor_B, LOW);
  digitalWrite(direction_Rightmotor_F, HIGH);
  digitalWrite(direction_Rightmotor_B, LOW);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);
  }
  void backwardLeft()
  {
  int leftmotor_speed = motor_speed * 0.43;
  int rightmotor_speed = motor_speed;
  digitalWrite(direction_Leftmotor_F, LOW);
  digitalWrite(direction_Leftmotor_B, HIGH);
  digitalWrite(direction_Rightmotor_F, LOW);
  digitalWrite(direction_Rightmotor_B, HIGH);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed); 
  }
  void backwardright()
  {
  int leftmotor_speed = motor_speed;
  int rightmotor_speed = motor_speed * 0.43;
  digitalWrite(direction_Leftmotor_F, LOW);
  digitalWrite(direction_Leftmotor_B, HIGH);
  digitalWrite(direction_Rightmotor_F, LOW);
  digitalWrite(direction_Rightmotor_B, HIGH);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed);  
  }
  void Stop(){
      Serial.println("stop");

    int leftmotor_speed = 0;
  int rightmotor_speed = 0;
  digitalWrite(direction_Leftmotor_F, HIGH);
  digitalWrite(direction_Leftmotor_B, LOW);
  digitalWrite(direction_Rightmotor_F, HIGH);
  digitalWrite(direction_Rightmotor_B, LOW);
  analogWrite(enableA, leftmotor_speed);
  analogWrite(enableB, rightmotor_speed); 
  }
