#include "Pixel.h"

Pixel::Pixel(const int &red, const int &green, const int &blue, const int &xCoord, const int &yCoord)
{
  this->red = red;
  this->green = green;
  this->blue = blue;
  this->xCoord = xCoord;
  this->yCoord = yCoord;
  this->brightness = 0.299 * red + 0.587 * green + 0.114 * blue;
}

float Pixel::getBrightness() const{
  return brightness;
}

void Pixel::print(){
  std::cout << this->red << " " << this->green << " " << this->blue << " " << this->xCoord << " " << this->yCoord << " " <<this->brightness <<std::endl;
}

bool Pixel::operator <(Pixel& pix){
  return this->brightness < pix.getBrightness();
}

bool Pixel::compareBrightness(Pixel* p1, Pixel* p2){
  return (*p1).getBrightness() < (*p2).getBrightness();
}

void Pixel::asd(const Pixel& a){
  std::cout << a.getBrightness();
}