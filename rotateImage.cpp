#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int angle = 0;

Mat src = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",CV_LOAD_IMAGE_COLOR);
Mat dst = Mat::zeros(src.size(),src.type());

void rotate(int,void *){

	Point2f pt(src.cols/2., src.rows/2.);    
    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    
    warpAffine(src, dst, r, Size(src.cols, src.rows));

    imshow("window",dst);
}

int main(){

	namedWindow("window",CV_WINDOW_AUTOSIZE);

	createTrackbar("angle","window",&angle,360,rotate);

	waitKey(0);
	
	return 0;
}