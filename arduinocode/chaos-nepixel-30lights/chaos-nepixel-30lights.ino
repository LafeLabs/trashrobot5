// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 30

int delay_time = 30;//ms

int x = 10;
int knob = 0;
int index = 0;


//Chaos demo
//calculate chaotic driven damped pendulum trajectory using fourth order Runge-Kutta
// 
 
  float t = 0.0;
  int period = 15;
  float y[] = {0.0,0.0};
  float E;
  float f0 = 0.0;  //velocity
  float f1 = 0.0;  //accelleration
  float f[] = {0.0,0.0};
  float k1[] = {0.0,0.0};
  float k2[] = {0.0,0.0};
  float k3[] = {0.0,0.0};
  float k4[] = {0.0,0.0};
  
  float theta = 0.0;
  float thetadot = 0.0;
  float force;
      
  float pi = 3.14159;

  float yindex = 0.1;
  float ynext[] = {0.0,0.0};
 
  float gamma = 0.4; 
  float omega0 = 0.65;
  float h = 0.1; //time step in fractions of natural period 
  float A = 1.3;  

 

 
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


// setup() function -- runs once at startup --------------------------------

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(150); // Set BRIGHTNESS to about 1/5 (max = 255)
  for(int i=0; i < strip.numPixels(); i++) { // For each pixel in strip...
        strip.setPixelColor(i, 0, 0, 0);         
  }      
  strip.show();                           
    Serial.begin(9600);

}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {


  force = 0;
  
  k1[0] = getf0(t,y,gamma,omega0,A,force);
  k1[1] = getf1(t,y,gamma,omega0,A,force);

  ynext[0] = y[0] + 0.5*h*k1[0];
  ynext[1] = y[1] + 0.5*h*k1[1];
  
  k2[0] = getf0(t+0.5*h,ynext,gamma,omega0,A,force);
  k2[1] = getf1(t+0.5*h,ynext,gamma,omega0,A,force);

  ynext[0] = y[0] + 0.5*h*k2[0];
  ynext[1] = y[1] + 0.5*h*k2[1];
  
  k3[0] = getf0(t+0.5*h,ynext,gamma,omega0,A,force);
  k3[1] = getf1(t+0.5*h,ynext,gamma,omega0,A,force);

  ynext[0] = y[0] + h*k3[0];
  ynext[1] = y[1] + h*k3[1];

  k4[0] = getf0(t+h,ynext,gamma,omega0,A,force);
  k4[1] = getf1(t+h,ynext,gamma,omega0,A,force);
  
  
  ynext[0] = y[0] + 0.1667*h*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
  ynext[1] = y[1] + 0.1667*h*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);  


  theta = 255.0*abs(y[0])/pi;
  thetadot = 255.0*abs(y[1])/pi;

  //wrap the angle around if it goes above or below pi
  if(ynext[0] >= pi){
     ynext[0] = ynext[0] - 2*pi;
  }
  if(ynext[0] <= -pi){
     ynext[0] = ynext[0] + 2*pi;
  }

  y[0] = ynext[0];
  y[1] = ynext[1];

  t = t + h;
         
  x = int(theta/10)%30;
  Serial.println(x);

    strip.setPixelColor(x, 255, 0, 0);         
    strip.show();                           
    delay(period);
    strip.setPixelColor(x, 0, 0, 0);               
  
}


float getf0(float t,float y[],float gamma, float omega0, float A,float force){
  float result;
  result = y[1];
  return result;
}
float getf1(float t,float y[],float gamma, float omega0,float A, float force){
  float result;
  result = -sin(y[0]) - gamma*y[1] + A*cos(omega0*t) + force;
  return result;
}
