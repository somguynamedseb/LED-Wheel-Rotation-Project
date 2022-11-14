#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <pixelwrite.h>
#include <animation.h>
#include <Vector.h>

Wheel::Wheel(){

}

void Wheel::setup()
{
    
    s01.begin(); //0 deg offset
    s02.begin(); //45 deg offset
    s03.begin(); //90 deg offset 
    s04.begin(); //135 deg offset
    s05.begin(); //180 deg offset
    s06.begin(); //225 deg offset
    s07.begin(); //270 deg offset
    s08.begin(); //315 deg offset

}
void Wheel::spin(int deg)
{
{  for (int i = 0; i <= (360/deg); i++)
{


      for (uint16_t j=0; j<(15);)
      {
        
        int truR = (j*3.33);
        int truD = deg * i;
        s01.setPixelColor(j,s01.Color(hueChk('r',truR,(truD+00)),hueChk('g',truR,(truD+00)),hueChk('b',truR,(truD+00)),hueChk('w',truR,(truD+00))));
        Serial.println("1");
        s02.setPixelColor(j,s02.Color(hueChk('r',truR,(truD+45)),hueChk('g',truR,(truD+45)),hueChk('b',truR,(truD+45)),hueChk('w',truR,(truD+45))));
        Serial.println("2");
        s03.setPixelColor(j,s03.Color(hueChk('r',truR,(truD+90)),hueChk('g',truR,(truD+90)),hueChk('b',truR,(truD+90)),hueChk('w',truR,(truD+90))));
        Serial.println("3");
        s04.setPixelColor(j,s04.Color(hueChk('r',truR,(truD+135)),hueChk('g',truR,(truD+135)),hueChk('b',truR,(truD+135)),hueChk('w',truR,(truD+135))));
        Serial.println("4");
        s05.setPixelColor(j,s05.Color(hueChk('r',truR,(truD+180)),hueChk('g',truR,(truD+180)),hueChk('b',truR,(truD+180)),hueChk('w',truR,(truD+180))));
        Serial.println("5");
        s06.setPixelColor(j,s06.Color(hueChk('r',truR,(truD+225)),hueChk('g',truR,(truD+225)),hueChk('b',truR,(truD+225)),hueChk('w',truR,(truD+225))));
        Serial.println("6");
        s07.setPixelColor(j,s07.Color(hueChk('r',truR,(truD+270)),hueChk('g',truR,(truD+270)),hueChk('b',truR,(truD+270)),hueChk('w',truR,(truD+270))));
        Serial.println("7");
        s08.setPixelColor(j,s08.Color(hueChk('r',truR,(truD+315)),hueChk('g',truR,(truD+315)),hueChk('b',truR,(truD+315)),hueChk('w',truR,(truD+315))));
        Serial.println("8");
        j++;
      }
     s01.show();
     s02.show();
     s03.show();
     s04.show();
     s05.show();
     s06.show();
     s07.show();
     s08.show();
      delay(50);
  }
}
}

int Wheel::hueChk(char rgbw,int pixelRad, int degOffset) 
{
  

  if (rgbw == 'r'){
    return (animation::arrayStore('r', (int((pixelRad) * cos(degOffset))),(int((pixelRad)* sin (degOffset))))); 
    }
  if (rgbw == 'g'){
    return(animation::arrayStore('g', (int((pixelRad) * cos(degOffset))),(int((pixelRad)* sin (degOffset))))); 
    }
  if (rgbw == 'b'){
    return(animation::arrayStore('b', (int((pixelRad) * cos(degOffset))),(int((pixelRad)* sin (degOffset))))); 
    }
  if (rgbw == 'w'){
    return(animation::arrayStore('w', (int((pixelRad) * cos(degOffset))),(int((pixelRad)* sin (degOffset))))); 
    }
    return 0;
}