

/*

FREE, PUBLIC DOMAIN
NO COPYRIGHT

OSCILLATOR
*/

int feedback = 0;
int x = 512;
int x0 = 512;
int drivePin  = 7;

void setup() {
  Serial.begin(115200);
  feedback = analogRead(A0);  
  pinMode(drivePin,OUTPUT);
  x = feedback;
  x0 = x;
 }

void loop() {
  feedback = analogRead(A0);  
  x = x0 - feedback;
  if(x > 3){
     digitalWrite(drivePin,HIGH);
  }
  else{
     digitalWrite(drivePin,LOW);    
  }
 
 Serial.println(x); 
 
  delay(10);
  
}
