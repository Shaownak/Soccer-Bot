int R_EN = 12;
int L_EN = 13;
int R_IS = 11;
int L_IS = 7;

//channel initialize
double ch1 = 2;
double ch2 = 4;
double ch3 = 10;

//motor1, motor3
int RPWM_1 = 3;
int LPWM_1 = 5;

//motor2, motor4
int RPWM_2 = 6;
int LPWM_2 = 9;



void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  
  //define pinmode
  

  pinMode(R_IS, OUTPUT);
  pinMode(L_IS, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  
  //motor1, motor3
  pinMode(RPWM_1 , OUTPUT);
  pinMode(LPWM_1, OUTPUT);

  //motor2, motor4 
  pinMode(RPWM_2 , OUTPUT);
  pinMode(LPWM_2, OUTPUT);
  

  digitalWrite(R_IS, LOW);
  digitalWrite(L_IS, LOW);
  
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  Serial.begin(9600);
}

void loop(){
  ch1 = pulseIn(2, HIGH);
  ch2 = pulseIn(4, HIGH);
  ch3 = pulseIn(10, HIGH);


  // initializing speed
  int i = ch3;
  
  double speed1 = ch3/7.9;

  if (ch1 == 0 && ch2 == 0) {
    reset();
 }
 
 else if((ch1>1530)&&(ch2>1530))
{     
forward(speed1);    
}

else if((ch1>1530)&&(ch2<1460))
{ 
   right(speed1);   

}

else if((ch1<1460)&&(ch2>1530))
{     
  left(speed1);
}

else if((ch1<1460)&&(ch2<1460))
{  
  backward(speed1);
}

else
{     
 reset();
}
 
}
  


void forward(double speed1) {
  analogWrite(RPWM_1, speed1);
  analogWrite(RPWM_2, speed1);
  analogWrite(LPWM_1, 0);
  analogWrite(LPWM_2, 0);
}

void backward(double speed1) {
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
  analogWrite(LPWM_1, speed1);
  analogWrite(LPWM_2, speed1);
}


void right(double speed1) {
 analogWrite(RPWM_1, speed1);
 analogWrite(LPWM_2, speed1);
 analogWrite(RPWM_2, 0);
 analogWrite(LPWM_1, 0);
  
  
}

void left(double speed1) {
 analogWrite(RPWM_1, 0);
 analogWrite(LPWM_2, 0);
 analogWrite(RPWM_2, speed1);
 analogWrite(LPWM_1, speed1); 
}

void reset() {
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
  analogWrite(LPWM_1, 0);
  analogWrite(LPWM_2, 0);
}
