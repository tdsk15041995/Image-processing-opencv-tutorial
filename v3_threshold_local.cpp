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

  Mat adaptive_mean,adaptive_gaussian;
  //adaptiveThreshold(inout,output,maxvalue,CV_ADAPTIVE_THRESH_MEAN_C | CV_ADAPTIVE_THRESH_GAUSSIAN_C,threshold type,blocksize, C)
 adaptiveThreshold(gray_image,adaptive_mean,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,7,11);
 adaptiveThreshold(gray_image,adaptive_gaussian,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,7,11);
  
 Mat global_thresholding;
  
  //threshold(ip,op,thresvalue,max,type)
  threshold(gray_image,global_thresholding,128,255,CV_THRESH_BINARY);

  imshow("Original image",input_image);
  imshow("Gray image",gray_image);
  imshow("adaptive_mean",adaptive_mean);
  imshow("Gaussian",adaptive_gaussian);
  imshow("Global thresholding",global_thresholding);


  
  waitKey(0);
  return 0;
}