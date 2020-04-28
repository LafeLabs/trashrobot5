
/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

STEPPER BUTTON DRIVE

*/


int knob = 0;

int button1pin = 2;
int button2pin = 3;
boolean button1 = false;
boolean button2 = false;

int coilPin = 5;

void setup() {
//  Serial.begin(115200);
  pinMode(button1pin,INPUT_PULLUP); 
  pinMode(button2pin,INPUT_PULLUP); 
  pinMode(coilPin,OUTPUT);
  digitalWrite(coilPin,LOW);
  knob = analogRead(A2);  

}

void loop() {
  knob = analogRead(A2);  
  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  

  if(!button1 || !button2){
     digitalWrite(coilPin,HIGH);
  }
  else{
     digitalWrite(coilPin,LOW);
  }

 // Serial.println(knob); 
 
  //delay(20);
  
}
