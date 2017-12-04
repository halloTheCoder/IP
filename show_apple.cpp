#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/a.png",1);

Mat tmp(img.rows,img.cols,CV_8UC3,Scalar(0));

int t1,t2,t3,t4,t5,t6 = 0;

void callback(int ,void *){
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			
			int r = img.at<cv::Vec3b>(i,j)[0];
			int g = img.at<cv::Vec3b>(i,j)[1];
			int b = img.at<cv::Vec3b>(i,j)[2];

			if((r > t1 && r < t2) && (g > t3 && g < t4) && (b > t5 || b < t6)){
				tmp.at<cv::Vec3b>(i,j)[0] = r;
				tmp.at<cv::Vec3b>(i,j)[1] = g;
				tmp.at<cv::Vec3b>(i,j)[2] = b;
			}
			else{
				tmp.at<cv::Vec3b>(i,j)[0] = 255;
				tmp.at<cv::Vec3b>(i,j)[1] = 255;
				tmp.at<cv::Vec3b>(i,j)[2] = 255;
			}
		}
	}
	imshow("window",tmp);
}


int main(){

	namedWindow("window",CV_WINDOW_AUTOSIZE);
	
	createTrackbar("track1","window",&t1,255,callback);

	createTrackbar("track2","window",&t2,255,callback);

	createTrackbar("track3","window",&t3,255,callback);

	createTrackbar("track4","window",&t4,255,callback);

	createTrackbar("track5","window",&t5,255,callback);

	createTrackbar("track6","window",&t6,255,callback);

	waitKey(0);

	return 0;
}