const int pingPin1 = 4; // Trigger Pin of Ultrasonic Sensor1
const int echoPin1 = 3; // Echo Pin of Ultrasonic Sensor1
const int pingPin2 = 6; // Trigger Pin of Ultrasonic Sensor2
const int echoPin2 = 5; // Echo Pin of Ultrasonic Sensor2
const int pingPin3 = 9; // Trigger Pin of Ultrasonic Sensor3
const int echoPin3 = 8; // Echo Pin of Ultrasonic Sensor3
long duration1,distance1; //variable for defining the distance and duration of each sensor
long duration2,distance2;
long duration3,distance3;
int en1=10; // pin to give pwm signals for motor 1 (motor speed)
int en2=11; // pin to give pwm signals for motor 2 (motor speed)
int in1=A0; //A1,A2, A3, A4 are the motor signals connected to analog input of arduino board
int in2=A1; //from the IN1, IN2, IN3, IN4 pins of motor driver
int in3=A2;
int in4=A3;
int D=800; // time delay varaible
int m=70;  //   motor speed is defined here

//this loop runs only once which initialises the pins of arduino
void setup()
{
pinMode(pingPin1, OUTPUT);
pinMode(pingPin2, OUTPUT);
pinMode(pingPin3, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(echoPin2, INPUT);
pinMode(echoPin3, INPUT);
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}
//for forward movement
void forward(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  } 
//for back movement
void back(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
//for forward Right movement
void fright(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }  
//for forward left movement
void fleft(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
//for back right movement
void bright(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }    
//for back left movement
void bleft(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }  
//for stopping all the movemnet
void stopp(){
  analogWrite(en1,m);
  analogWrite(en2,250); 
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }  
//This loop runs continously
void loop()
{
  d1();
  d2();
  d3();
freeroam();
}

// this function is used to measure the distance travelled by each pulse 
void d1(){
digitalWrite(pingPin1, LOW);
delayMicroseconds(2);
digitalWrite(pingPin1, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1 = microsecondsToCentimeters(duration1);}

void d2(){
digitalWrite(pingPin2, LOW);
delayMicroseconds(2);
digitalWrite(pingPin2, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2 = microsecondsToCentimeters(duration2);}

void d3(){
digitalWrite(pingPin3, LOW);
delayMicroseconds(2);
digitalWrite(pingPin3, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distance3 = microsecondsToCentimeters(duration3);
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

//This is the main code for running the vehicle considering the distance calculated using sensors
void freeroam()
{
     if(distance2 < 25 && distance3 < 25 && distance1 < 25) 
     {
        bright();
     }
     if(distance1 > 25 && distance3 > 25 && distance2 < 25)
     {
      fright();
     }
      if(distance1 > 25 && distance2 > 25 && distance3 < 25)
     {
      fleft();
     }
     if(distance2 > 25 && distance3 > 25 && distance1 < 25) //IF ONLY CENTER DETECTED
    {
      bleft();
      delay(D);
    }

        if(distance2 < 25 && distance3 < 25 && distance1 > 25) //IF LEFT AND RIGHT DETECTED
          {
            
            bright(); 
          }

        if (distance1 < 25 && distance3 < 25 && distance2 >25) //IF FRONT AND RIGHT DETECTED
          {
            
            fleft();
          }

        if (distance1 < 25 && distance2 < 25 && distance3 > 25) //IF FRONT AND LEFT DETECTED
          {
            
            fright();
          }
    
        if(distance2 >= 25 && distance3 >= 25 && distance1 >= 25) /// e.g. if it is safe to go forward
          {
            forward();
          }
          
}
