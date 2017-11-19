/*
Author:- Swapnil Chaughule
Email:- chswapnil@gmail.com
*/

#include<iostream>
#include<cmath>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"HaarDwt.h"


using namespace std;
using namespace cv;


int main()
{
cout.precision(7);
var2d hdwt;
Mat A = imread("/home/swapnil/Documents/Images/lena3.jpg");//Image file location
Mat img;
cvtColor(A,img,CV_BGR2GRAY);
imshow("COVER",img);
int i,j;
if(!img.empty())
{
cout<<"Image read\n";
Mat dimg(img.rows,img.cols,CV_64FC1,Scalar::all(0));

img.convertTo(dimg,CV_64FC1,1.0/255.0);

hdwt = haar2d(dimg);


Mat temp = ihaar2d(hdwt);
imshow("Final",temp);
waitKey(0);

}
else
{
cout<<"Image is empty\n";
}
return 0;
}

