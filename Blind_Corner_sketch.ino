/*********************************************************************************************************************
  Program: Blind Corner
  Author: Emmanuel Gbey
  Description: This sketch is to serve as the software component for the obstacle detection device at blind corners
**********************************************************************************************************************/

int const trigPin1 = 10; // declaring global variables
int const echoPin1 = 9;
int const GreenLED1 = 8;
int const RedLED1 = 7;
int const PRpin1 = 6;

int const trigPin2 = 5;
int const echoPin2 = 4;
int const GreenLED2 = 3;
int const RedLED2 = 2;
int const PRpin2 = 1;

void setup() {// put your setup code here, to run once:

  pinMode(trigPin1, OUTPUT); //trig pins will have pulses output
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT); //echo pins will be input to get pulse width
  pinMode(echoPin2, INPUT);
  pinMode(GreenLED1, OUTPUT); //set LED pins to be output to display signal
  pinMode(GreenLED2, OUTPUT);
  pinMode(RedLED1, OUTPUT);
  pinMode(RedLED2, OUTPUT);
  pinMode(PRpin1, INPUT); // setting the Photoresistors(PRpin1 and PRpin2) as an inputs
  pinMode(PRpin2, INPUT);

}

void loop() {// put your main code here, to run repeatedly:

  int duration1, distance1; // duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration2, distance2;

  digitalWrite(trigPin1, LOW); //trig pin set low
  delayMicroseconds(2000); //2000 microseconds pulse width on trigpin1
  digitalWrite(trigPin1, HIGH); // trig pin set high
  delayMicroseconds(10); //10 microseconds pulse width
  digitalWrite(trigPin1, LOW); //set trig pin low

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration1 = pulseIn(echoPin1, HIGH); // measuring the time taken for signal to reach obstacle and back as echo in microseconds
  duration2 = pulseIn(echoPin2, HIGH);

  distance1 = ((duration1) / 2) / 0.0343; //distance is half the duration divided by 29.1(from datasheet)
  distance2 = ((duration2) / 2) / 0.0343;

  if ((distance1 <= 50) && (PRpin1 == LOW)) { //if distance is <=5ocm and PRpin1 is low, then RedLED1 should on, otherwise, GreenLED1 should on
    digitalWrite(RedLED1, HIGH);
    delay(20);   // delay for 1 minute
  }
  else {
    digitalWrite(RedLED1, LOW);
    delay(20);  // delay for 1 minute
  }
  if ((distance1>50) && (PRpin1 ==HIGH)){
     digitalWrite(GreenLED1,HIGH);
  }
  else {
    digitalWrite(GreenLED1,LOW);
    }
 
 
 if (((distance2 <= 50) && (PRpin2 == LOW))) { //if distance is <=5ocm and PRpin2 is low, then RedLED1 should on, otherwise, GreenLED2 should on
    digitalWrite(RedLED2, HIGH);
    delay(20);   // delay for 1 minute
  }
  else {
    digitalWrite(RedLED2, LOW);
    delay(20);  // delay for 1 minute
  }
  if (((distance2>50) && (PRpin2 ==HIGH))){
     digitalWrite(GreenLED2,HIGH);
  }
  else {
    digitalWrite(GreenLED2,LOW);
    }
  delay(1);

}
