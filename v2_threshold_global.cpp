#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <stdio.h>


using namespace std;
using namespace cv;

int main(int argc,const char** argv){
  Mat input_image=imread(argv[1],1);
  Mat gray_image;
  cvtColor(input_image,gray_image,CV_BGR2GRAY);

  Mat binary;
  threshold(gray_image,binary,100,255,CV_THRESH_BINARY);

  Mat truncate;
  threshold(gray_image,truncate,150,255,CV_THRESH_TRUNC);

  imshow("Original image",input_image);
  imshow("gray image",gray_image);
  imshow("Binary",binary);
  imshow("truncate",truncate);
  
  waitKey(0);
  return 0;
}