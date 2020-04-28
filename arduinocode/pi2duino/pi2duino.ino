
/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

STEPPER BUTTON DRIVE

*/


int motor1pluspin = 9;
int motor1minuspin = 10;
int motor2pluspin = 11;
int motor2minuspin = 12;
int x=0;
int y=0;
int z=0;
int w=0;

void setup() {
  Serial.begin(9600);
  pinMode(motor1pluspin,OUTPUT);
  pinMode(motor1minuspin,OUTPUT);
  pinMode(motor2pluspin,OUTPUT);
  pinMode(motor2minuspin,OUTPUT);

  pinMode(2,INPUT);
  pinMode(3,INPUT);

  pinMode(7,INPUT);
  pinMode(8,INPUT);

  digitalWrite(motor1pluspin,LOW);
  digitalWrite(motor1minuspin,LOW);
  digitalWrite(motor2pluspin,LOW);
  digitalWrite(motor2minuspin,LOW);

}

void loop() {

  if(digitalRead(2)){
    x =1;
    digitalWrite(motor1pluspin,HIGH);    
  }
  else{
    x=0;
    digitalWrite(motor1pluspin,LOW);
  }
  if(x == 0 && digitalRead(3)){
     digitalWrite(motor1minuspin,HIGH);
     y = 1;
  }
  else{
     digitalWrite(motor1minuspin,LOW);
     y = 0;
  }

  if(digitalRead(7)){
    z =1;
    digitalWrite(motor2pluspin,HIGH);    
  }
  else{
    z=0;
    digitalWrite(motor2pluspin,LOW);
  }
  if(z == 0 && digitalRead(8)){
     digitalWrite(motor2minuspin,HIGH);
     w = 1;
  }
  else{
     digitalWrite(motor2minuspin,LOW);
     w = 0;
  }


/*    if(digitalRead(3){
      digitalWrite(motor1minuspin,HIGH);        
      y=1;
    }
    else{
      digitalWrite(motor1minuspin,LOW);                
      y=0;
    }*/
    
  

  if(digitalRead(7)){
    z =1;
  }
  else{
    z=0;
  }
  if(digitalRead(8)){
    w =1;
  }
  else{
    w=0;
  }

  Serial.print(x);
  Serial.print(","); 
  Serial.print(y);
  Serial.print(","); 
  Serial.print(z);
  Serial.print(","); 
  Serial.println(w); 
  delay(10);
}
