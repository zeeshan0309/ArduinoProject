int buzPin = 7;
int trigPin = 8;
int echoPin = 4;
float speed = 0.0347;
float dist;
float pingTime;
int buzHigh = 50;
int buzMid  =130;
int buzFar = 600;
int delayFar = 260;


void setup() {
  pinMode(buzPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTime = pulseIn(echoPin,HIGH);
  dist = (speed*pingTime*0.5);
  if(dist<=10.0 && dist>5.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzHigh);
    digitalWrite(buzPin,LOW);
    delay(buzHigh);
  }
  else if((dist>10.0) && (dist<30.0))
  {
    digitalWrite(buzPin,HIGH);
    delay(buzMid);
    digitalWrite(buzPin,LOW);
    delay(buzMid);
  }
  else if(dist>=30.0 && dist<100.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzFar);
    digitalWrite(buzPin,LOW);
    delay(delayFar);
  }
  else if(dist<=5.0){
    digitalWrite(buzPin,HIGH);
    delay(20);
    digitalWrite(buzPin,LOW);
    delay(20);
  }  
}
