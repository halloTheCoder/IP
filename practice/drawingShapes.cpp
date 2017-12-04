#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",CV_LOAD_IMAGE_COLOR);

int main(){
	line(img,Point(100,200),Point(200,300),Scalar(255,255,244),5);

	namedWindow("window",CV_WINDOW_AUTOSIZE);
	
	imshow("window",img);
	waitKey(0);

	circle(img,Point(55,55),32,Scalar(125,231,0),-1);
	imshow("window",img);
	waitKey(0);

	putText(img,"Hey All",Point(74,74),FONT_HERSHEY_SIMPLEX,1,Scalar(102,21,45),3);
	imshow("window",img);
	waitKey(0);

	return 0;
}