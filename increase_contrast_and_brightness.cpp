#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

double alpha = 2.2;
int beta = 50;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",1);

Mat new_img(img.rows,img.cols,CV_8UC3,Scalar(0));

int main(){
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			for(int c=0;c<3;c++)
				new_img.at<cv::Vec3b>(i,j)[c] = (((alpha * (img.at<cv::Vec3b>(i,j)[c]) + beta) > 255) ? (alpha * (img.at<cv::Vec3b>(i,j)[c]) + beta) 
												: 255);
		}
	}

	namedWindow("window1",CV_WINDOW_AUTOSIZE);
	imshow("window1",img);

	namedWindow("window2",CV_WINDOW_AUTOSIZE);
	imshow("window2",new_img);

	waitKey(0);
	return 0;
}