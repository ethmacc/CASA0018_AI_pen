#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 8
#define LEDPin D5
Adafruit_NeoPixel pixels(NUMPIXELS, LEDPin);
uint32_t yellow = pixels.Color(20, 20, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  Serial.println("Turning neopixel on");
  //pixels.fill(yellow, 0, 2);
  pixels.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
}
