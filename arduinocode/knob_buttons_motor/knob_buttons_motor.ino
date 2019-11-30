
int knob = 0;

int button1pin = 3;
int button2pin = 2;
int motorpin = 5;
boolean button1 = false;
boolean button2 = false;

void setup() {
    pinMode(button1pin,INPUT_PULLUP); 
    pinMode(button2pin,INPUT_PULLUP); 
    pinMode(motorpin,OUTPUT);
    analogWrite(motorpin,0);
    knob = analogRead(A2);
    Serial.begin(9600);

}

void loop() {

  button1 = digitalRead(button1pin);  
  button2 = digitalRead(button2pin);  
  knob = analogRead(A2);
  if(!button1 && button2){
    analogWrite(motorpin,255);
    Serial.println("button 1");
  }  
  if(!button2 && button1){
    analogWrite(motorpin,knob/4);
    Serial.println("button 2");
  }
  if(button2 && button1){
    analogWrite(motorpin,0);
  }
  if(!button2 && !button1){
    analogWrite(motorpin,0);
  }
  delay(100);  
  Serial.println(knob); 

}
