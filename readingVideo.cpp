#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat frame,gray,edge,draw;

int lower,upper;

void edge_detection(int,void *){
	//pass
}

int main(){
	VideoCapture vid(0);
	
	namedWindow("window",CV_WINDOW_AUTOSIZE);
	namedWindow("input",CV_WINDOW_AUTOSIZE);

	createTrackbar("lower","window",&lower,100,edge_detection);
	createTrackbar("upper","window",&upper,200,edge_detection);

	int frame_width = vid.get(CV_CAP_PROP_FRAME_WIDTH);            //Width of the frames in the video stream
  	int frame_height = vid.get(CV_CAP_PROP_FRAME_HEIGHT); 	       //Height of the frames in the video stream
	
	VideoWriter video("/home/akash/Desktop/coding/IP/openCV/outcpp.avi",CV_FOURCC('P','I','M','1'),10, Size(frame_width,frame_height)); 

	while(1){
		vid.read(frame);

		cvtColor(frame,gray,CV_BGR2GRAY);
		
		Canny(gray,edge,lower,upper,3);

		edge.convertTo(draw,CV_8U);             //dont know the purpose

		video.write(gray);

		imshow("input",frame);
		imshow("window",draw);

		if(waitKey(30) >= 0)
			break;
	}

	vid.release();
	video.release();

	destroyAllWindows();

	return 0;
}