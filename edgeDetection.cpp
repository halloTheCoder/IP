#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/rubik.jpg",CV_LOAD_IMAGE_GRAYSCALE);
Mat new_img = Mat::zeros(img.size(),img.type());

/*
Mat img_bw;

int t = 0;

void callback(int,void *){
	img_bw = img > t;

	imshow("window",img_bw);
}*/

int gradX(int x,int y){
	return img.at<uchar>(y-1, x-1) + 2*img.at<uchar>(y, x-1) + img.at<uchar>(y+1, x-1) - img.at<uchar>(y-1, x+1) - 2*img.at<uchar>(y, x+1) - img.at<uchar>(y+1, x+1);
}

int gradY(int x,int y){
	return img.at<uchar>(y-1, x-1) + 2*img.at<uchar>(y-1, x) + img.at<uchar>(y-1, x+1) - img.at<uchar>(y+1, x-1) - 2*img.at<uchar>(y+1, x) - img.at<uchar>(y+1, x+1);
}


int main(){
	namedWindow("window",CV_WINDOW_AUTOSIZE);
	namedWindow("input",CV_WINDOW_AUTOSIZE);

	//createTrackbar("threshold","window",&t,255,callback);

	int r = img.rows;
	int c = img.cols;
	int gx,gy,sum=0;

	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			gx = gradX(j,i);
			gy = gradY(j,i);
			sum = abs(gx) + abs(gy);
            sum = sum > 255 ? 255:sum;
            sum = sum < 0 ? 0 : sum;
            new_img.at<uchar>(i,j) = sum;
		}
	}
	imshow("input",img);
	imshow("window",new_img);

	waitKey(0);
	return 0;
}