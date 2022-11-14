#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <pixelwrite.h>
#include <animation.h>
#include <LinkedList.h>
#include <Vector.h>

Wheel Wheel1;
/*
IMPORTANT SHIT
DO NOT GENERATE BEFORE ADDING STRIPES
DO NOT SPIN BEFORE GENERATE 
DO NOT EAT TACOS ON A THURSDAY
*/


void setup() {
  Serial.begin(9600);
  animation::setup();
  Wheel1.setup();
  }

void loop() {




  animation::stripe_color_add(225,0,0,0,25);
  animation::stripe_color_add(0,255,0,0,25);
  animation::stripe_color_add(0,0,255,0,25);
  animation::stripe_color_add(0,0,0,255,25);


  animation::stripe_generate();
  Serial.println("gemerated");
  Wheel1.spin(2);

}