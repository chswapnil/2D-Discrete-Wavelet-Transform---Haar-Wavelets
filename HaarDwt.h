#include<iostream>
#include<cmath>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#ifndef HAARDWT
#define HAARDWT

using namespace std;
using namespace cv;

//Structure to store the return value of haar2d function
struct var2d
{
Mat LL, LH, HL, HH;
};

//Structure to store the return value of haar1d function
struct var1d
{
Mat L,H;
};

//Functions
var1d haar1d(Mat dimg);//To calculate 1D DWT using HAAR
var2d haar2d(Mat dimg);//To calculate 2D DWT using HAAR
Mat ihaar1d(var1d var);//To calculate 1D Inverse DWT using HAAR
Mat ihaar2d(var2d var);//To calculate 2D Inverse DWT using HAAR

#endif
