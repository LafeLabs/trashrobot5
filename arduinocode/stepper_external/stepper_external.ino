
/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

STEPPER EXTERNAL DRIVE, NO PULL UP


need to combine this with button, just use different pins!
*/


int knob = 0;

int button1pin = 2;
int button2pin = 3;
boolean button1 = false;
boolean button2 = false;

int pinArray[] = {9,11,10,12};
int pinIndex = 0;
int pulseTime = 10;//ms
int x = 512;

void setup() {
  Serial.begin(115200);
  pinMode(button1pin,INPUT); 
  pinMode(button2pin,INPUT); 
  pinMode(pinArray[0],OUTPUT);
  pinMode(pinArray[1],OUTPUT); 
  pinMode(pinArray[2],OUTPUT); 
  pinMode(pinArray[3],OUTPUT);
  digitalWrite(pinArray[0],LOW);
  digitalWrite(pinArray[1],LOW);
  digitalWrite(pinArray[2],LOW);
  digitalWrite(pinArray[3],LOW);
  knob = analogRead(A2);  

}

void loop() {
  knob = analogRead(A2);  
  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  

  if(!button1 && button2){
    x += 1;
    digitalWrite(pinArray[x%4],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[x%4],LOW);
    delay(pulseTime);
    Serial.println("button1");
  }  
  if(!button2 && button1){
    x -=1;
    digitalWrite(pinArray[x%4],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[x%4],LOW);
    delay(pulseTime);
    Serial.println("button2");
  }
  if(button2 && button1){

  }
  if(!button2 && !button1){

  }

 
  Serial.println(x); 
 
  //Serial.print(","); 
  //Serial.println(x); 
  //delay(20);
  
}
