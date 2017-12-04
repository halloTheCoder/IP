#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int alpha_slider = 0;
const int alpha_slider_max = 100;
double alpha,beta;

int t = 0;

Mat img1 = imread("/home/akash/Desktop/coding/IP/openCV/3D-Matplotlib.png",CV_LOAD_IMAGE_COLOR);
Mat img2 = imread("/home/akash/Desktop/coding/IP/openCV/mainsvmimage.png",CV_LOAD_IMAGE_COLOR);

Mat new_img(img1.rows,img1.cols,CV_8UC3,Scalar(0));

void callback(int,void *){
	/*for(int i=0;i<img1.rows;i++){
		for(int j=0;j<img1.cols;j++){
			if(img1.at<uchar>(i,j) > t)
				new_img.at<uchar>(i,j) = 255;                   //uchar :: unsigned char 
			else
				new_img.at<uchar>(i,j) = 0;
		}
	}*/
	alpha = (double)alpha_slider/alpha_slider_max;
	beta = 1 - alpha;

	addWeighted(img1,alpha,img2,beta,0.0,new_img);

	imshow("window",new_img);

}

int main(){
	namedWindow("window",CV_WINDOW_AUTOSIZE);

	createTrackbar("overlap","window",&alpha_slider,alpha_slider_max,callback);

	callback(alpha_slider,0);

	waitKey(0);
	return 0;
}