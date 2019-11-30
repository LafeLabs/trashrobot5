
/*
www.trashrobot.org
FREE, PUBLIC DOMAIN
NO COPYRIGHT

STEPPER KNOB DIRECT DRIVE

*/

int pinArray[] = {9,11,10,12};
int pinIndex = 0;
int pulseTime = 10;//ms
int knob = 512;
int x = 512;

void setup() {
  Serial.begin(115200);
  pinMode(pinArray[0],OUTPUT);
  pinMode(pinArray[1],OUTPUT); 
  pinMode(pinArray[2],OUTPUT); 
  pinMode(pinArray[3],OUTPUT);
  digitalWrite(pinArray[0],LOW);
  digitalWrite(pinArray[1],LOW);
  digitalWrite(pinArray[2],LOW);
  digitalWrite(pinArray[3],LOW);
  knob = analogRead(A2);  
  x = knob;
}

void loop() {
  knob = analogRead(A2);  

  if(abs(x - knob) > 5){
     if(x > knob){
        x = x - 5;
     }
     else{
        x = x + 5;
     }
     digitalWrite(pinArray[x%4],HIGH);
     delay(pulseTime);
     digitalWrite(pinArray[x%4],LOW);
     delay(pulseTime);
     Serial.println(pinArray[x%4]);  
  }
 
 //    Serial.println(knob); 
 
  //Serial.print(","); 
  //Serial.println(x); 
  //delay(20);
  
}
