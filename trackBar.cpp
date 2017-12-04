#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",0);
	
Mat tmp(img.rows,img.cols,CV_8UC1,Scalar(0));

int t=0;

void callback(int,void *){
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			if(img.at<uchar>(i,j) > t){
				tmp.at<uchar>(i,j) = 255;
			}
			else{
				tmp.at<uchar>(i,j) = 0;
			}
		}
	}
    imshow("window", tmp);
}

int main(){	
	namedWindow( "window", CV_WINDOW_AUTOSIZE ); 
	createTrackbar("binary", "window", &t, 255, callback );  
	//callback(0,0);  
    waitKey(0);
    return 0;
}