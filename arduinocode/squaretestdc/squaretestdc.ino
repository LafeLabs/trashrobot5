
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

int pinArray[] = {9,10,11,12};
int pinIndex = 0;
int pulseTime = 250;//ms

void setup() {
  Serial.begin(115200);
  pinMode(button1pin,INPUT_PULLUP); 
  pinMode(button2pin,INPUT_PULLUP); 
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

  button1 = !digitalRead(button1pin);  
  button2 = !digitalRead(button2pin);  

  if(button1){
    digitalWrite(pinArray[0],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[0],LOW);
    digitalWrite(pinArray[2],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[2],LOW);
    digitalWrite(pinArray[1],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[1],LOW);
    digitalWrite(pinArray[3],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[3],LOW);
    
  }

  if(button2){
    digitalWrite(pinArray[0],HIGH);
    digitalWrite(pinArray[3],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[0],LOW);
    digitalWrite(pinArray[3],LOW);
    
    digitalWrite(pinArray[1],HIGH);
    digitalWrite(pinArray[2],HIGH);
    delay(pulseTime);
    digitalWrite(pinArray[1],LOW);
    digitalWrite(pinArray[2],LOW);
    
  }


   
}
