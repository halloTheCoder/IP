#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

double alpha;
int beta;

int alpha_slider = 0;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",CV_LOAD_IMAGE_COLOR);

Mat new_img = Mat::zeros(img.size(),img.type());

void change(int,void *){
	alpha = (double)alpha_slider/5;

	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			for(int c=0;c<3;c++){
				new_img.at<cv::Vec3b>(i,j)[c] = saturate_cast<uchar>(img.at<cv::Vec3b>(i,j)[c] * alpha + beta);
			}
		}
	}

	imshow("window",new_img);
}

int main(){
	namedWindow("window",CV_WINDOW_AUTOSIZE);

	createTrackbar("brightness","window",&alpha_slider,10,change);

	createTrackbar("contrast","window",&beta,20,change);

	waitKey(0);

	return 0;
}