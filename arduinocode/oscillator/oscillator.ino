

/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

OSCILLATOR
*/

int feedback = 0;
int x = 512;
int x0 = 512;
int drivePin  = 5;
int counter = 0;
int triggertime = 150;//ms
boolean coilon = false;
int delaytime = 10;//ms

void setup() {
  Serial.begin(115200);
  feedback = analogRead(A0);  
  pinMode(drivePin,OUTPUT);
  x = feedback;
  x0 = x;
 }

void loop() {
  counter++;
  feedback = analogRead(A0);  
  x = x0 - feedback;
  if(x > 3){
     digitalWrite(drivePin,HIGH);
     coilon = true;
  }
  else{
     digitalWrite(drivePin,LOW);    
     coilon = false;
  }

  if(counter*delaytime > triggertime){
    if(coilon == true){
     digitalWrite(drivePin,LOW);    
     coilon = false;
    }
    else{
     digitalWrite(drivePin,HIGH);
     coilon = true;      
    }
    counter = 0;
  }
 
 Serial.println(x); 
 
  delay(delaytime);//10 ms
  
}
