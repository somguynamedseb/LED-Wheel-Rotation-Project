#include <Arduino.h>
#include <animation.h>
#include <string.h>
#include <Vector.h>



int storage_array1[10];
long storage_array2[10];
Vector<int> storage_array3 [100]; 
int storage_array4[100];
int stripeCounter = 0;
Vector<long> stripecolor;
Vector<int> stripewidth;
Vector<Vector<int>> red;
Vector<Vector<int>> green;
Vector<Vector<int>> blue;
Vector<Vector<int>> white;


void animation::setup(){
    stripewidth.setStorage(storage_array1);
    stripecolor.setStorage(storage_array2);
    red.setStorage(storage_array3);
    green.setStorage(storage_array3);
    blue.setStorage(storage_array3);
    white.setStorage(storage_array3);

}




void animation::stripe_color_add(int r,int g,int b, int w, int width){
    long colorsum = createHex(r,g,b,w);
    stripecolor.push_back(colorsum); stripewidth.push_back(width);

};

void animation::stripe_generate(){
    int numofstripes = stripecolor.size();
    int array_x;   

    for (int i = 0; i < numofstripes; i++)
    {
        array_x = array_x + stripewidth.at(i); // gets the width from the list value 
    }  
    for (int i=0; i< red.max_size(); i++){
        red[i].setStorage(storage_array4);
        blue[i].setStorage(storage_array4);
        green[i].setStorage(storage_array4);
        white[i].setStorage(storage_array4);
    }    
    int widthsum = 0;
    int tempwidth= 0;
    for (int i = 0; i < numofstripes; i++) //limited by the number of stripes
    {
        widthsum = widthsum + stripewidth.at(i);

        Serial.println("i=");
        Serial.println(i);

        for (int x = tempwidth; x < widthsum; x++) //limited by the width of the current stripe
        {

            
            for (int y = 0; y < 100; y++)
            {
                red[x][y] = createRGBA(stripecolor.at(i), 'r');
                green[x][y] = createRGBA(stripecolor.at(i), 'g');
                blue[x][y] = createRGBA(stripecolor.at(i), 'b');
                white[x][y] = createRGBA(stripecolor.at(i), 'w');
            }
        }
        tempwidth= tempwidth + stripewidth.at(i);
        
    }

};

long animation::createHex(long r, long g, long b, long a)
{   
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
           
}
int animation::createRGBA(long hex,char hue){
    if (hue== 'r')
    {
        return (((hex >> 24) & 0xFF));
    }
    if (hue== 'g')
    {
        return (((hex >> 16) & 0xFF));
    }
    if (hue== 'b')
    {
        return (((hex >> 8) & 0xFF));
    }
    else
    {
        return (((hex & 0xFF)));
    }

}

int animation::arrayStore(char rgbw,int x, int y){
    if (rgbw== 'r')
    {
        return (red[x][y]);
    }
    if (rgbw== 'g')
    {
        return (green[x][y]);
    }
    if (rgbw== 'b')
    {
        return (blue[x][y]);
    }
    else
    {
        return (white[x][y]);
    }
    return 0;
} 