#include <Arduino.h>
#include <MX1508.h>

#define PINA 9
#define PINB 10
#define NUMPWM 2
#define PINC 11
#define PIND 12

MX1508 motorA(PINA,PINB, FAST_DECAY, NUMPWM);

class MySensor{

public:
 int IRPIN;

 MySensor(int irpin){
  IRPIN=irpin;
  pinMode(IRPIN,INPUT);
  digitalRead(IRPIN);
 }
 int read(){
  return (digitalRead(IRPIN));
 }
};
MySensor mysensor(2);
MySensor mysensor2(3);
MySensor mysensor3(4);
MySensor mysensor4(5);


class Mymotors : public MySensor{

 public:
  



};

void go(){

 for(int i; i<255;i++){
     motorA.motorGo(i);
     delay(100);
     if (i==254){
      i=0;
      break;
     }
 }

}
 void stop(){

  motorA.stopMotor();
 }

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(mysensor.read());
      
  if(mysensor.read()==1){
    go();
  }
  else{
    stop();
  }
}