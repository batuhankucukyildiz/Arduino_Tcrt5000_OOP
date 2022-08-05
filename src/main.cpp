
//@author:Batuhan Kucukyildiz

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


int list[20]={};   // Verileri tutacağımız liste alanı 

void readn(){      // Kağıt Okuma işlemi 
int clock=0;
for (int a; a<200; a+5){
  motorA.motorGo(a);
  delay(1000);  // Satır satır okuma hissi veren kısım 
  if(mysensor.read()==1 || mysensor2.read()==1 || mysensor3.read()==1 || mysensor4.read()==1){
    if(mysensor.read()==1 && mysensor2.read()==0&& mysensor4.read()==0 && mysensor4.read()==0){
     list[clock]=4;
     clock++;
    }
    if(mysensor.read()==0 && mysensor2.read()==1&& mysensor4.read()==0 && mysensor4.read()==0){
     list[clock]=5;
     clock++;
    }
    if(mysensor.read()==0 && mysensor2.read()==0&& mysensor4.read()==1 && mysensor4.read()==0){
     list[clock]=6;
     clock++;
    }
    if(mysensor.read()==0 && mysensor2.read()==0&& mysensor4.read()==0 && mysensor4.read()==1){
     list[clock]=7;
     clock++;
    }
  }
  if(a==199)
   {
    a=0;
    break;
   }
  
}
pageread();
}

void pageread(){




}
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

}