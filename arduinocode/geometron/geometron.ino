
/*
FREE, PUBLIC DOMAIN
NO COPYRIGHT
*/

int unit = 100;//drive time in ms
int side = 100;//drive time in ms

int buttonPin1 = 2;
int buttonPin2 = 3;
boolean button1 = false;
boolean button2 = false;

int triangleLeft = 14;//A0
int triangleRight = 15;
int squareLeft = 14;
int squareRight = 15;
int pentagramLeft = 14;
int pentagramRight = 15;

String hypercube[8];


void setup() {

//<hypercube>

  hypercube[0] = "bdddgkhl";
  hypercube[1] = "CD";
  hypercube[2] = "bnmgnmgnmgnmg";
  hypercube[3] = "bnmhnmhnmhnmh";
  hypercube[4] = "";
  hypercube[5] = "";
  hypercube[6] = "";
  hypercube[7] = "";

//</hypercube>

  pinMode(buttonPin1,INPUT_PULLUP); 
  pinMode(buttonPin2,INPUT_PULLUP); 

  pinMode(triangleLeft,OUTPUT); 
  pinMode(triangleRight,OUTPUT); 
  pinMode(squareLeft,OUTPUT); 
  pinMode(squareRight,OUTPUT); 
  pinMode(pentagramLeft,OUTPUT); 
  pinMode(pentagramRight,OUTPUT); 

//  pinMode(A0,OUTPUT); 
 // digitalWrite(A0,HIGH);

  digitalWrite(triangleLeft,HIGH);
  digitalWrite(triangleRight,HIGH);
  digitalWrite(squareLeft,HIGH);
  digitalWrite(squareRight,HIGH);
  digitalWrite(pentagramLeft,HIGH);
  digitalWrite(pentagramRight,HIGH);

}

void loop() {

  button1 = !digitalRead(buttonPin1);  
  if(button1){
     geometronSequence("bdn");
    // digitalWrite(A0,LOW);
    // delay(200);
    // digitalWrite(A0,HIGH);

  }
  button2 = !digitalRead(buttonPin2);  
  if(button2){
         geometronSequence("bdm");

//       geometronSequence(hypercube[1]);
  }
  
}

void geometronSequence(String glyph){
   //for loop thru the String
   int index = 0;
   for(index = 0;index < glyph.length();index++){
      geometronAction(glyph.charAt(index));
   }
}

void geometronAction(char action){
  if(action == 'a'){
     delay(side);
  }
  if(action == 'b'){
     side = unit;
  }
  if(action == 'c'){
    side /= 2;
  }
  if(action == 'd'){
    side *= 2;
  }
  if(action == 'e'){
     digitalWrite(triangleLeft,LOW);
     delay(side);
     digitalWrite(triangleLeft,HIGH);
  }
  if(action == 'f'){
     digitalWrite(triangleRight,LOW);
     delay(side);
     digitalWrite(triangleRight,HIGH);
  }
  if(action == 'g'){
     digitalWrite(squareLeft,LOW);
     delay(side);
     digitalWrite(squareLeft,HIGH);
  }
  if(action == 'h'){
     digitalWrite(squareRight,LOW);
     delay(side);
     digitalWrite(squareRight,HIGH);
  }
  if(action == 'i'){
     digitalWrite(pentagramLeft,LOW);
     delay(side);
     digitalWrite(pentagramLeft,HIGH);
  }
  if(action == 'j'){
     digitalWrite(pentagramRight,LOW);
     delay(side);
     digitalWrite(pentagramRight,HIGH);
  }
  if(action == 'k'){
     digitalWrite(triangleLeft,LOW);
     digitalWrite(pentagramLeft,LOW);
     delay(side);
     digitalWrite(triangleLeft,HIGH);
     digitalWrite(pentagramLeft,HIGH);
  }
  if(action == 'l'){
     digitalWrite(triangleRight,LOW);
     digitalWrite(pentagramRight,LOW);
     delay(side);
     digitalWrite(triangleRight,HIGH);
     digitalWrite(pentagramRight,HIGH);
  }
  if(action == 'm'){
     digitalWrite(triangleRight,LOW);
     digitalWrite(pentagramLeft,LOW);
     delay(side);
     digitalWrite(triangleRight,HIGH);
     digitalWrite(pentagramLeft,HIGH);
  }
  if(action == 'n'){
     digitalWrite(triangleLeft,LOW);
     digitalWrite(pentagramRight,LOW);
     delay(side);
     digitalWrite(triangleLeft,HIGH);
     digitalWrite(pentagramRight,HIGH);
  }
  if(action == 'A'){
    geometronSequence(hypercube[0]);
  }
  if(action == 'B'){
    geometronSequence(hypercube[1]);
  }
  if(action == 'C'){
    geometronSequence(hypercube[2]);
  }
  if(action == 'D'){
    geometronSequence(hypercube[3]);
  }
  if(action == 'E'){
    geometronSequence(hypercube[4]);
  }
  if(action == 'F'){
    geometronSequence(hypercube[5]);
  }
  if(action == 'G'){
    geometronSequence(hypercube[6]);
  }
  if(action == 'H'){
    geometronSequence(hypercube[7]);
  }

}
