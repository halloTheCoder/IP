#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/rubik.jpg",CV_LOAD_IMAGE_COLOR);

Mat edge = Mat::zeros(img.size(),img.type());
Mat gray = Mat::zeros(img.size(),img.type());
Mat draw = Mat::zeros(img.size(),img.type());

int lower = 0;
int upper = 0;

void callback(int,void *){
	Canny(gray,edge,lower,upper,3);

	edge.convertTo(draw,CV_8U);

	imshow("window",edge);
}

int main(){
	cvtColor(img,gray,CV_BGR2GRAY);
   
	namedWindow("window",CV_WINDOW_AUTOSIZE);

	createTrackbar("upper","window",&upper,200,callback);

	createTrackbar("lower","window",&lower,150,callback);

	waitKey(0);

	return 0;
}