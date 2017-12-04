#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",1);
Mat new_img(img.rows/2,img.cols,CV_8UC3,Scalar(0));

int main(){
	int x=0;
	for(int i=0;i<img.rows;i++){
		if(i%2 == 0){
			for(int j=0;j<img.cols;j++){
				new_img.at<Vec3b>(x,j)[0] = img.at<Vec3b>(i,j)[0];
				new_img.at<Vec3b>(x,j)[1] = img.at<Vec3b>(i,j)[1];
				new_img.at<Vec3b>(x,j)[2] = img.at<Vec3b>(i,j)[2];
			}
			x++;
		}
	}

	namedWindow("window1",CV_WINDOW_AUTOSIZE);
	imshow("window1",img);

	namedWindow("window2",CV_WINDOW_AUTOSIZE);
	imshow("window2",new_img);
	
	waitKey(0);
	return 0;
}