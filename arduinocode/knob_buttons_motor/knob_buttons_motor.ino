//Trash Robot Code for uno shield v5
//knob controls an analog voltage in pin A2 which ranges from 0 to 1023
//motor is PWM controlled via a transistor from digital pin 5
//buttons connect to ground, with internal pullup resistor from digital pins 2 and 3
//pushing button D2 down turns motor on with speed set by knob. 
//Knob ranges from 0 to 1023 but PWM output ranges from 0 to 255 so knob is divided by 4 to get output
//pushing button D3 turns motor on in full power mode(PWM value = 255)
//modify this code to create any kind of motor control or button/switch/knob activated devices
//this code is from https://github.com/LafeLabs/trashrobot5/tree/master/arduinocode
//no copyright of any kind. 
//NO MONEY
//NO MINING
//NO PROPERTY
//DEATH TO COPYRIGHT!!!!! INTELLECTUAL "PROPERTY" IS VIOLENCE!!!  DESTROY SILICON VALLEY!!!!

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
    analogWrite(motorpin,knob/4);
    Serial.println("button 1");
  }  
  if(!button2 && button1){
    analogWrite(motorpin,255);
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
