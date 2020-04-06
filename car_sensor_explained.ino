//program for proximity sensor with buzzer;

int buzPin = 7;       //declare pin for Buzzer;
int trigPin = 8;      //declare pin for trigger pin of UltraSonic sensor; 
int echoPin = 4;      //declare pin for echo pin of UltraSonic sensor;
float speed = 0.0347; //declare speed of sound in air @ room temp;
float dist;           //declare variable for containing distance sensed;
float pingTime;       //declare variable for containing echo time;
int buzNear = 20;     //declare buzzing time for very close proximity;
int buzHigh = 50;     //declare buzzing time for close proximity;
int buzMid  =130;     //declare buzzing time for mid proximity;
int buzFar = 600;     //declare buzzing time for far off object;
int delayFar = 260;


void setup() {
  pinMode(buzPin,OUTPUT);     //set buzzer & trigger pin as outpin;
  pinMode(trigPin,OUTPUT);    
  pinMode(echoPin,INPUT);     //set echo pin as input;

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);          //creating a pulse for sensing distance;
  pingTime = pulseIn(echoPin,HIGH);   //read the echoTime, &hence the distance;
  dist = (speed*pingTime*0.5);        
  
  if(dist<=10.0){
    digitalWrite(buzPin,HIGH);         //simple conditional statements changing frequency based upon the distance sensed
    delay(20);
    digitalWrite(buzPin,LOW);
    delay(20);
  }  
  else if(dist<=30.0 && dist>10.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzHigh);
    digitalWrite(buzPin,LOW);
    delay(buzHigh);
  }
  else if((dist>30.0) && (dist<60.0))
  {
    digitalWrite(buzPin,HIGH);
    delay(buzMid);
    digitalWrite(buzPin,LOW);
    delay(buzMid);
  }
  else if(dist>=60.0 && dist<120.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzFar);
    digitalWrite(buzPin,LOW);
    delay(delayFar);
  }
  
}
