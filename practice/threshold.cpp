#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/hidden.jpg",CV_LOAD_IMAGE_GRAYSCALE);

Mat new_img = Mat::zeros(img.size(),img.type());

int threshold_type = 0,threshold_value = 0;

void calc_threshold(int,void *){
	threshold(img,new_img,threshold_value,255,threshold_type);

	imshow("window",new_img);
}

int main(){
	namedWindow("window",CV_WINDOW_AUTOSIZE);

	createTrackbar("ThresholdValue","window",&threshold_value,255,calc_threshold);
	createTrackbar("ThresholdType","window",&threshold_type,4,calc_threshold);

	waitKey(0);
	return 0;
}