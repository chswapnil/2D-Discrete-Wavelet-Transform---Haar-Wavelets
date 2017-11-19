#include "HaarDwt.h"


//Function to calculate 1D Haar based DWT
var1d haar1d(Mat dimg)
{
Mat L(dimg.rows,dimg.cols/2,CV_64FC1,Scalar::all(0));
Mat H(dimg.rows,dimg.cols/2,CV_64FC1,Scalar::all(0));
int i;
for(i=0;i<dimg.cols/2;i++)
{
L.col(i)=(dimg.col(2*i)+dimg.col(2*i+1))/sqrt(2);
H.col(i)=(dimg.col(2*i)-dimg.col(2*i+1))/sqrt(2);
}

var1d ret;
ret.L = L.clone();//Storing Low Pass values
ret.H = H.clone();//Storing High Pass values
return ret;
}

//Function to calculate 2D Haar based DWT
var2d haar2d(Mat dimg)
{
var1d ret1,ret2;
var2d ret;
int i;
//Returns L and H by applying Haar 1D on rows
ret1 = haar1d(dimg);
//Apply Transpose to apply Haar 1D on columns
Mat Lt = ret1.L.t();
Mat Ht = ret1.H.t(); 


//Returns A and H by applying Haar 1D on columns
ret1 = haar1d(Lt);
//Returns V and D by applying Haar 1D on columns
ret2 = haar1d(Ht);

//Stores the final value in var2d structures
ret.LL = ret1.L.t();
ret.LH = ret1.H.t();
ret.HL = ret2.L.t();
ret.HH = ret2.H.t();

return ret;
}

//Function to calculate 1D HAAR Based Inverse DWT
Mat ihaar1d(var1d var)
{
int i;
Mat ret(var.L.rows,(var.L.cols)*2,CV_64FC1,Scalar::all(0));
for(i=0;i<var.L.cols;i++)
{
ret.col(2*i) = (var.L.col(i)+var.H.col(i))/sqrt(2);
ret.col(2*i+1) = (var.L.col(i)-var.H.col(i))/sqrt(2);
}

return ret;
}

//Function to calculate 2D HAAR Based Inverse DWT
Mat ihaar2d(var2d var)
{
int i;
var1d temp1,temp2;
Mat ret(var.LL.rows*2,var.LL.cols*2,CV_64FC1,Scalar::all(0));
temp1.L = var.LL.t();
temp1.H = var.LH.t();
temp2.L = var.HL.t();
temp2.H = var.HH.t();
Mat L(temp1.L.rows, temp1.L.cols*2,CV_64FC1,Scalar::all(0));
Mat H(temp2.L.rows, temp2.L.cols*2,CV_64FC1,Scalar::all(0));
//Inverse Haar Dwt for columns
for(i=0;i<temp1.L.cols;i++)
{
L.col(2*i) = (temp1.L.col(i)+temp1.H.col(i))/sqrt(2);
L.col(2*i+1) = (temp1.L.col(i)-temp1.H.col(i))/sqrt(2);
H.col(2*i) = (temp2.L.col(i)+temp2.H.col(i))/sqrt(2);
H.col(2*i+1) = (temp2.L.col(i)-temp2.H.col(i))/sqrt(2);
}

Mat Lt = L.t();
Mat Ht = H.t();
//Inverse Haar Dwt for rows
for(i=0;i<Lt.cols;i++)
{
ret.col(2*i) = (Lt.col(i)+Ht.col(i))/sqrt(2);
ret.col(2*i+1) = (Lt.col(i)-Ht.col(i))/sqrt(2);
}

return ret;
}

