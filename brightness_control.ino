#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int ledPin = 10;
int brightness=255;
unsigned long key_value = 0;


void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)){
    
    if (results.value == 0xFFFFFFFF)
         results.value = key_value;

    if(results.value==0x1FEA05F){
      brightness-=51;
     
      if (brightness<0){brightness=0;}
      
    }
    else if(results.value==0x1FE609F){
      brightness+=51;
   
      if (brightness>255){brightness=255;}
     }
    
     key_value = results.value;
     irrecv.resume();
  }
brightnessControl(brightness);
}

void brightnessControl(int value){
  analogWrite(ledPin,value);
  }
