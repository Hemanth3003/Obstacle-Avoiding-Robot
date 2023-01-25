int FrontmotorRightA=2; //Front Right motor clockwise 
int FrontmotorRightB=3;//Front Right motot anti clockwise 
int FrontmotorLeftA=4;//Front Left motor clockwise
int FrontmotorLeftB=5;//Front Left motor clockwise

int trigger =6;//Trig pin
int echo=7;//Echo pin
  int BackmotorRightA=8;//Back Right motor clockwise
  int BackmotorRightB=9;//Back Right motot anti clockwise
  int BackmotorLeftA=10;// Back Left motor clockwise
  int BackmotorLeftB=11;//Back Left motor clockwise
int LED1=15; //Red Led when stop 
int LED2=16;// green Led for start
void setup()
{
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT); 
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT); 
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  
Serial.begin(9600);
}
void loop()
{
long time,distance;
  digitalWrite(trigger,LOW);// Trig pin Low
  delayMicroseconds(2); // Trig pin HIGH for 10 miro seconds
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  time= pulseIn(echo,HIGH);
  distance= time/2/29.1;// Calculating distance
  Serial.println(distance);//Print distance on serial monitor
  delay(1000);
  if (distance<150)
    // 1 inches =2.54cm, 5 feet = 150cm
  {
   digitalWrite(2,LOW);// Front motor stop
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
    digitalWrite(8,LOW);//Back motor stop
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
   digitalWrite(15,HIGH);// RED Light on
   digitalWrite(16,LOW); // Green Led on
  }
  else
  {
   digitalWrite(2,LOW);//Front motor start
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);
    digitalWrite(8,LOW);//Back motor Start
   digitalWrite(9,HIGH);
   digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
   digitalWrite(15,LOW);//RED Light Off
    digitalWrite(16,HIGH);//Green Light Off
  }
   
}

