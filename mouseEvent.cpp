#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/lena.png",1);

void callback(int event,int x,int y,int flags,void *){
	if(event == EVENT_LBUTTONDOWN){
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }

    else if( event == EVENT_RBUTTONDOWN ){
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }

    else if  ( event == EVENT_MBUTTONDOWN ){
        cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }

    else if(event == EVENT_MOUSEMOVE){
        cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
    }
}

int main(){
	namedWindow("window",CV_WINDOW_AUTOSIZE);

	setMouseCallback("window",callback);

	imshow("window",img);

	waitKey(0);
	return 0;
}