#include<Servo.h>
int servoPin = 5;
int posDown = 60;
int posUp = 100;
int readPin1 = A0;
int readPin2 = A1;
int readVal1;
int readVal2;
Servo myPointer;

void setup() {
  Serial.begin(9600);
  pinMode(readPin1, INPUT);
  pinMode(readPin2, INPUT);
  myPointer.attach(servoPin);
}

void loop() {
  readVal1 = analogRead(readPin1);
  readVal2 = analogRead(readPin2);
  Serial.println(readVal1);
  if(readVal1<1100 && readVal1>801){
    if(readVal1<920){
    for(int pos=posUp; pos>=posDown; pos-=5){
      myPointer.write(pos);
      delay(10);
    }
    delay(100);
    for(int pos=posDown; pos<=posUp; pos+=5){
      myPointer.write(pos);
      delay(10);
    }
  }
  }

  else if(readVal1>600 && readVal1<800){
    if(readVal1>700){
    for(int pos=posUp; pos>=posDown; pos-=5){
      myPointer.write(pos);
      delay(10);
    }
    delay(100);
    for(int pos=posDown; pos<=posUp; pos+=5){
      myPointer.write(pos);
      delay(10);
    }
  }
  }

if(readVal2<1100 && readVal2>801){
    if(readVal2<920){
    for(int pos=posUp; pos>=posDown; pos-=5){
      myPointer.write(pos);
      delay(10);
    }
    delay(100);
    for(int pos=posDown; pos<=posUp; pos+=5){
      myPointer.write(pos);
      delay(10);
    }
  }
  }

  else if(readVal2>600 && readVal2<800){
    if(readVal2>700){
    for(int pos=posUp; pos>=posDown; pos-=5){
      myPointer.write(pos);
      delay(10);
    }
    delay(100);
    for(int pos=posDown; pos<=posUp; pos+=5){
      myPointer.write(pos);
      delay(10);
    }
  }
  }

}
  
  
