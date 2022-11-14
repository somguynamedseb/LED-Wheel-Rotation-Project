#pragma once

#include <Vector.h>
using namespace std;

namespace animation{
        
        void setup();
        void stripe_animate(int speed);
        void stripe_generate();
        void stripe_color_add(int r,int g,int b, int w, int width);
        long createHex(long r, long g, long b, long a);
        int createRGBA(long hex, char hue);
        int arrayStore(char rgbw, int x, int y);
        int freeMemory();
}