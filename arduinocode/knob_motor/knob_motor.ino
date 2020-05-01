
int knob = 0;

int motorpin = 5;

void setup() {
    pinMode(motorpin,OUTPUT);
    analogWrite(motorpin,0);
    knob = analogRead(A2);
    Serial.begin(9600);

}

void loop() {

  knob = analogRead(A2);
  if(knob<100){
    analogWrite(motorpin,0); 
  }
  else{
      analogWrite(motorpin,knob/4); 
  }
  Serial.println(knob); 

}
