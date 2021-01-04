#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

class Pixel {
  private:
    int red,green,blue;
    int xCoord, yCoord;
    float brightness;
  public:
    Pixel(const int &red, const int &green, const int &blue, const int &xCoord, const int &yCoord);
    void print();
    float getBrightness() const;
    bool operator < (Pixel &pix);
    static bool compareBrightness(Pixel* p1, Pixel* p2);
    void asd(const Pixel& a);
    
};

#endif // PIXEL_H