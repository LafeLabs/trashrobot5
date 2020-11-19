
/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

STEPPER BUTTON DRIVE
*/

int button1pin = 14;
int button2pin = 15;
int button3pin = 16;
int button4pin = 17;

int motorpin1 = 8;
int motorpin2 = 9;
int motorpin3 = 10;
int motorpin4 = 11;

boolean button1 = false;
boolean button2 = false;
boolean button3 = false;
boolean button4 = false;

void setup() {
  Serial.begin(115200);
  pinMode(button1pin,INPUT_PULLUP); 
  pinMode(button2pin,INPUT_PULLUP); 
  pinMode(button3pin,INPUT_PULLUP); 
  pinMode(button4pin,INPUT_PULLUP); 

  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT); 
  pinMode(motorpin3,OUTPUT);
  pinMode(motorpin4,OUTPUT); 

  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,LOW);
  digitalWrite(motorpin3,LOW);
  digitalWrite(motorpin4,LOW);

  
}

void loop() {

  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  
  button3 = digitalRead(button3pin);  
  button4 = digitalRead(button4pin);  

  if(!button1){
    Serial.println("button1");
    digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW);
    digitalWrite(motorpin4,LOW);
  }  
  if(!button2){
    Serial.println("button2");
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,HIGH);
    digitalWrite(motorpin3,LOW);
    digitalWrite(motorpin4,LOW);
  }
  if(!button3){
    Serial.println("button3");
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,HIGH);
    digitalWrite(motorpin4,LOW);
  }  
  if(!button4){
    Serial.println("button4");
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW);
    digitalWrite(motorpin4,HIGH);
  }
  if(button1 && button2 && button3 && button4){
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
    digitalWrite(motorpin3,LOW);
    digitalWrite(motorpin4,LOW);
    
  }

  
}
