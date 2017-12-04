#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main(){
	Mat img1 = imread("/home/akash/Desktop/coding/IP/openCV/drawing1.jpg",1);
	Mat img2 = imread("/home/akash/Desktop/coding/IP/openCV/drawing2.jpg",1);

	Mat img_add,img_or,img_xor,img_not1,img_not2;

	namedWindow("img1",CV_WINDOW_AUTOSIZE);
	namedWindow("img2",CV_WINDOW_AUTOSIZE);
	namedWindow("add",CV_WINDOW_AUTOSIZE);
	namedWindow("or",CV_WINDOW_AUTOSIZE);
	namedWindow("xor",CV_WINDOW_AUTOSIZE);
	namedWindow("not1",CV_WINDOW_AUTOSIZE);
	namedWindow("not2",CV_WINDOW_AUTOSIZE);

	bitwise_and(img1,img2,img_add);
	bitwise_or(img1,img2,img_or);
	bitwise_xor(img1,img2,img_xor);
	bitwise_not(img1,img_not1);
	bitwise_not(img2,img_not2);

	imshow("img1",img1);
	imshow("img2",img2);
	imshow("add",img_add);
	imshow("or",img_or);
	imshow("xor",img_xor);
	imshow("not1",img_not1);
	imshow("not2",img_not2);

	waitKey(0);
	return 0;
}