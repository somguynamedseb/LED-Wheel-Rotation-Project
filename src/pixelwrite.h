#pragma once
#include <Vector.h>
class Wheel
{
    
public:

    unsigned rad =50;
  Adafruit_NeoPixel s01 = Adafruit_NeoPixel(15, 22, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s02 = Adafruit_NeoPixel(15, 24, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s03 = Adafruit_NeoPixel(15, 26, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s04 = Adafruit_NeoPixel(15, 28, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s05 = Adafruit_NeoPixel(15, 30, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s06 = Adafruit_NeoPixel(15, 32, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s07 = Adafruit_NeoPixel(15, 34, NEO_WRGB + NEO_KHZ800);
    Adafruit_NeoPixel s08 = Adafruit_NeoPixel(15, 26, NEO_WRGB + NEO_KHZ800);


    Wheel();
    void setup();
    void spin(int deg);
    void clear();
private:
    int hueChk(char rgbw,int pixelRad, int degOffset);
};
