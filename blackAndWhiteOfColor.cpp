#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",1);
	
Mat new_img = Mat::zeros(img.size(),img.type());

int main(){
	int r = img.rows;
	int c = img.cols;

	vector<int> push;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			push.push_back((img.at<Vec3b>(i,j)[0] + img.at<Vec3b>(i,j)[1] + img.at<Vec3b>(i,j)[2])/3);
		}
	}

	int balance = accumulate(push.begin(),push.end(),0) / push.size(); 

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(((img.at<Vec3b>(i,j)[0] + img.at<Vec3b>(i,j)[1] + img.at<Vec3b>(i,j)[2])/3) > balance){
				new_img.at<Vec3b>(i,j)[0] = 255;
				new_img.at<Vec3b>(i,j)[1] = 255;
				new_img.at<Vec3b>(i,j)[2] = 255;
			}
			else{
				new_img.at<Vec3b>(i,j) = (0,0,0);
			}
		}
	}

	namedWindow("window1",CV_WINDOW_AUTOSIZE);
	imshow("window1",img);
	
	namedWindow("window2",CV_WINDOW_AUTOSIZE);	
	imshow("window2",new_img);

	waitKey(0);
}