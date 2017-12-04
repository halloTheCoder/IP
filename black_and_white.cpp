#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img;

int main(){
	img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",0);
	
	Mat new_img = Mat::zeros(img.size(),img.type());

	int r = img.rows;
	int c = img.cols;

	int sum = 0;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			sum += img.at<uchar>(i,j);
		}
	}
	
	int balance = sum/(r*c);

	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			if(img.at<uchar>(i,j) > balance){
				new_img.at<uchar>(i,j) = 255;
			}
			else{
				new_img.at<uchar>(i,j) = 0;
			}
		}
	}

	namedWindow("window1",CV_WINDOW_AUTOSIZE);
	imshow("window1",img);
	
	namedWindow("window2",CV_WINDOW_AUTOSIZE);	
	imshow("window2",new_img);

	waitKey(0);
	return 0;
}