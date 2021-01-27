String symbol0 = "A";
String symbol1 = "B";
String symbol2 = "C";
String symbol3 = "D";
String symbol4 = "AAA";
String symbol5 = "BBB";
String symbol6 = "CCC";
String symbol7 = "DDD";




int delayus = 500;//delayMicroseconds(delayus);

int unit = 100;
int side = unit;

int x = 0;

int x7 = 110;
int x6 = 222;
int x5 = 333;
int x4 = 444;
int x3 = 555;
int x2 = 668;
int x1 = 784;
int x0 = 902;
int delta = 10;

//these are the pin numbers of the buttons on the controller.  Connect to ground to activate.
int xleftPin = 10;
int xrightPin = 7;
int yawayPin = 8;
int ytowardsPin = 9;
int zdownPin = 6;
int zupPin = 5;

int goPin = 11;
int stopPin = 12;

//connect these pins to the MP6500 stepper motor control board:
int dirPin3 = 19;
int stepPin3 = 18;
int enPin3 = 17;
int dirPin1 = 16;
int stepPin1 = 15;

int enPin1 = 13;

int dirPin2 = 2;
int stepPin2 = 3;
int enPin2 = 4;

boolean xleftBool = false;
boolean xrightBool = false;
boolean yawayBool = false;
boolean ytowardsBool = false;
boolean zdownBool = false;
boolean zupBool = false;
boolean goBool = false;
boolean stopBool = false;

int select = 0;

void setup() {
    x = analogRead(A0);
    Serial.begin(9600);

    pinMode(xleftPin,INPUT_PULLUP); 
    pinMode(xrightPin,INPUT_PULLUP); 
    pinMode(yawayPin,INPUT_PULLUP); 
    pinMode(ytowardsPin,INPUT_PULLUP); 
    pinMode(zdownPin,INPUT_PULLUP); 
    pinMode(zupPin,INPUT_PULLUP); 
    pinMode(goPin,INPUT_PULLUP); 
    pinMode(stopPin,INPUT_PULLUP); 

    pinMode(dirPin1,OUTPUT);
    pinMode(stepPin1,OUTPUT);
    pinMode(enPin1,OUTPUT);
    pinMode(dirPin2,OUTPUT);
    pinMode(stepPin2,OUTPUT);
    pinMode(enPin2,OUTPUT);
    pinMode(dirPin3,OUTPUT);
    pinMode(stepPin3,OUTPUT);
    pinMode(enPin3,OUTPUT);

    digitalWrite(dirPin1,LOW);
    digitalWrite(stepPin1,LOW);
    digitalWrite(enPin1,HIGH);
    digitalWrite(dirPin2,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(enPin2,HIGH);
    digitalWrite(dirPin3,LOW);
    digitalWrite(stepPin3,LOW);
    digitalWrite(enPin3,HIGH);
    
    Serial.begin(9600);

}

void loop() { 

  x = analogRead(A0);

  if(x > x0 - delta && x < x0 + delta){
    select = 0;
  }
  if(x > x1 - delta && x < x1 + delta){
    select = 1;
  }
  if(x > x2 - delta && x < x2 + delta){
    select = 2;
  }
  if(x > x3 - delta && x < x3 + delta){
    select = 3;
  }
  if(x > x4 - delta && x < x4 + delta){
    select = 4;
  }
  if(x > x5 - delta && x < x5 + delta){
    select = 5;
  }
  if(x > x6 - delta && x < x6 + delta){
    select = 6;
  }
  if(x > x7 - delta && x < x7 + delta){
    select = 7;
  }
  if(x<50){
    select = -1;
  }

  
   Serial.println(select); 

  xleftBool = !digitalRead(xleftPin);
  xrightBool = !digitalRead(xrightPin);
  yawayBool = !digitalRead(yawayPin);
  ytowardsBool = !digitalRead(ytowardsPin);
  zdownBool = !digitalRead(zdownPin);
  zupBool = !digitalRead(zupPin);
  goBool = !digitalRead(goPin);
  stopBool = !digitalRead(stopPin);
  
   //Serial.println(goBool); 
  if(goBool){
    if(select == 0){
      geometronSequence(symbol0);
    }
    if(select == 1){
      geometronSequence(symbol1);
    }
    if(select == 2){
      geometronSequence(symbol2);
    }
    if(select == 3){
      geometronSequence(symbol3);
    }
    if(select == 4){
      geometronSequence(symbol4);
    }
    if(select == 5){
      geometronSequence(symbol5);
    }
    if(select == 6){
      geometronSequence(symbol6);
    }
    if(select == 7){
      geometronSequence(symbol7);
    }


    
  }

  if(xleftBool){
     moveLeft(1);
  }
  if(xrightBool){
     moveRight(1);
  }
  if(zdownBool){
    moveUp(1); 
  }
  if(zupBool){
    moveDown(1); 
  }
  if(yawayBool){
    moveAway(1);
  }
  if(ytowardsBool){
    moveTowards(1);
 }
}

void moveLeft(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,HIGH);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin2,HIGH);   
}

void moveRight(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,LOW);
     digitalWrite(enPin3,LOW);
    
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 

     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin3,HIGH);   

}

void moveDown(int nSteps){
     digitalWrite(dirPin1,HIGH);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,HIGH);
     digitalWrite(enPin3,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin1,HIGH);   
     digitalWrite(enPin3,HIGH);   

}

void moveUp(int nSteps){
     digitalWrite(dirPin1,LOW);
     digitalWrite(enPin1,LOW);
     digitalWrite(dirPin3,LOW);
     digitalWrite(enPin3,LOW);     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin1,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin1,LOW);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin3,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin3,HIGH);    
     digitalWrite(enPin1,HIGH);

}

void moveAway(int nSteps){
     digitalWrite(dirPin2,LOW);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}

void moveTowards(int nSteps){
     digitalWrite(dirPin2,HIGH);
     digitalWrite(enPin2,LOW);
     
     for(int index = 0;index < nSteps;index++){
       digitalWrite(stepPin2,HIGH);
       delayMicroseconds(delayus); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(delayus); 
     }          
     digitalWrite(enPin2,HIGH);   
}


void geometronAction(char action){
  stopBool = !digitalRead(stopPin);
  if(action == 'a'){
     moveRight(side);
  }
  if(action == 'b'){
     moveLeft(side);
  }
  if(action == 'c'){
    moveAway(side);
  }
  if(action == 'd'){
    moveTowards(side);
  }
  if(action == 'e'){
    moveUp(side);
  }
  if(action == 'f'){
    moveDown(side);
  }
  if(action == 'g'){
    side /= 2;
  }
  if(action == 'h'){
    side *= 2;
  }
  if(action == 'A'){
    geometronSequence("ggahhef");
  }
  if(action == 'B'){
    geometronSequence("ggbhhef");
  }
  if(action == 'C'){
    geometronSequence("ggchhef");
  }
  if(action == 'D'){
    geometronSequence("ggdhhef");
  }
  if(action == 'E'){
    geometronSequence("ggahh");
  }
  if(action == 'F'){
    geometronSequence("ggbhh");
  }
  if(action == 'G'){
    geometronSequence("ggchh");
  }
  if(action == 'H'){
    geometronSequence("ggdhh");
  }

}

void geometronSequence(String glyph){
   //for loop thru the String
   int index = 0;
   for(index = 0;index < glyph.length();index++){
    if(!stopBool){
      geometronAction(glyph.charAt(index));      
    }
   }
}
