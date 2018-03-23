//Objective:Take an image as a input ,display it and then save it
//Date:22-07-17
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <stdio.h>


using namespace std;
using namespace cv;
int main(int argc,const char** argv)
{
  Mat img1=imread(argv[1],CV_LOAD_IMAGE_UNCHANGED);
  Mat img2;
  cvtColor(img1,img2,CV_BGR2GRAY);
  imshow("Original image",img1);
  imshow("Gray scale image",img2);
  imwrite("grayscale.png",img2);
  waitKey(0);
  return 0;
}
