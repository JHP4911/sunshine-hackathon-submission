#include <Servo.h>

Servo servoA;
Servo servoB;
Servo servoC;

int ledTemoin = 8;
float angleA = 40;
float angleB = 40;
float angleC = 40;

float speedA = 0.03;   // deg per millisecond
float speedB = 0.06;
float speedC = 0.12;

bool AGoUp = true;
bool BGoUp = true;
bool CGoUp = true;


void setup() {
  // put your setup code here, to run once:

  pinMode(ledTemoin, OUTPUT); // led temoin
  digitalWrite(ledTemoin,HIGH);
  servoA.attach(9);     //servo A
  servoB.attach(11);    //servo B
  servoC.attach(10);    //servo C
  delay(500);
  servoA.writeMicroseconds((-2160+1260)*float(45)/90 + 2160);
  servoB.writeMicroseconds((-1975+1130)*float(45)/90 + 1975);
  servoC.writeMicroseconds((-1955+1130)*float(45)/90 + 1955);

  delay(300);

}

void loop() {
  digitalWrite(ledTemoin , millis() / 500 % 2 ); // blink led

  servoA.writeMicroseconds((-2160+1260)*float(angleA)/90 + 2160);
  servoB.writeMicroseconds((-1975+1130)*float(angleB)/90 + 1975);
  servoC.writeMicroseconds((-1955+1130)*float(angleC)/90 + 1955);

  if(angleA >= 90){
    AGoUp = false;  
  }if(angleA <= 40){
    AGoUp = true;  
  }


  if(angleB >= 90){
    BGoUp = false;  
  }if(angleB <= 40){
    BGoUp = true;  
  }


  if(angleC >= 90){
    CGoUp = false;  
  }if(angleC <= 40){
    CGoUp = true;  
  }




  if(AGoUp == true){
    angleA += speedA;
  }else{
    angleA -= speedA;
  }

  if(BGoUp == true){
    angleB += speedB;
  }else{
    angleB -= speedB;
  }

  if(CGoUp == true){
    angleC += speedC;
  }else{
    angleC -= speedC;
  }


  delay(1);
}
