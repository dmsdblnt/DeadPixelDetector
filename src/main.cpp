#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <list>
#include "Pixel.h"

void firstSolution(cv::Mat &image){
  
  //create list to store dead pixels
  std::list<std::pair<cv::Vec3b,std::pair<int,int>>> deadPixels;

  //iterate through the image's pixels and push the dead ones to list
  for (int i=0;i<image.rows;i++){
    for(int j=0; j<image.cols;j++){
      if((image.at<cv::Vec3b>(i,j)[0] != 0 || image.at<cv::Vec3b>(i,j)[1] != 0 || image.at<cv::Vec3b>(i,j)[2] != 0)){
        std::pair<int,int> coord(i,j);
        std::pair<cv::Vec3b,std::pair<int,int>> pixelData (image.at<cv::Vec3b>(i,j), coord);
        deadPixels.push_back(pixelData);
      }
    }
  }

  //sort all the dead pixels
  deadPixels.sort([](const std::pair<cv::Vec3b,std::pair<int,int>> &a, const std::pair<cv::Vec3b,std::pair<int,int>> &b) -> bool{
    float aBrightness = 0.299*(int)a.first[2] + 0.587*(int)a.first[1] + 0.114*(int)a.first[0];
    float bBrightness = 0.299*(int)b.first[2] + 0.587*(int)b.first[1] + 0.114*(int)b.first[0];
    return aBrightness > bBrightness;
  });

  //print the first 100 element in the sorted list
  int i = 0;
  auto it = deadPixels.begin();
  while(i<100){
    std::cout << (int)it->first[0] << " " << (int)it->first[1] << " " << (int)it->first[2] << " " << it->second.first << " " << it->second.second <<std::endl;
    ++it;
    ++i;
  }
}

void secondSolution(cv::Mat &image){

  //create list that contains the pixels
  std::list<Pixel*> deadPixels;

  //iterate through all of the pixels, and add non-black pixels to the list
  for (int i=0;i<image.rows;i++){
    for(int j=0; j<image.cols;j++){
      if((image.at<cv::Vec3b>(i,j)[0] != 0 || image.at<cv::Vec3b>(i,j)[1] != 0 || image.at<cv::Vec3b>(i,j)[2] != 0)){
        Pixel *pix = new Pixel((int)image.at<cv::Vec3b>(i,j)[0], (int)image.at<cv::Vec3b>(i,j)[1], (int)image.at<cv::Vec3b>(i,j)[2], j, i);
        deadPixels.push_back(pix);
      }
    }
  }

  //sort the pixels using overloaded < operator
  deadPixels.sort([](Pixel* pix1, Pixel* pix2){
    return *pix2 < *pix1;
  });

  //print the first 100 element
  int i = 0;
  auto it = deadPixels.begin();
  while(i<100){
    (*it)->print();
    ++it;
    ++i;
  }
}


int main(int argc, char *argv[]){

  //argument existence check
  std::string filename = "";
  if(argc > 1){
    filename = argv[1];
  }else if(argc == 1){
    std::cout << "Filename not added" << std::endl;
    return 1;
  }

  //read the image
  cv::Mat image = cv::imread(filename);

  //image existence check
  if(image.empty()){
    std::cout << "no image with this name" << std::endl;
    return 1;
  }else{
    // firstSolution(image);
    secondSolution(image);
  }

  return 0;
}

//blue, green, red