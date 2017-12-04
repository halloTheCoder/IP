#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;
using namespace cv;

Mat img = imread("/home/akash/Desktop/coding/IP/openCV/filter.png",1);
Mat img2 = imread("/home/akash/Desktop/coding/IP/openCV/filter2.png",1);
Mat img3 = imread("/home/akash/Desktop/coding/IP/openCV/filter3.png",1);
Mat img4 = imread("/home/akash/Desktop/coding/IP/openCV/filter4.png",1);

//Mat new_img_dial,new_img_eros;

Mat erosion(Mat img){
	Mat new_img_eros = img.clone();
	int r = img.rows;
	int c = img.cols;
	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			vector<int> push;
			for(int x=i-1;x<=i+1;x++){
				for(int y=j-1;y<=j+1;y++){
					push.push_back((img.at<Vec3b>(x,y)[0] + img.at<Vec3b>(x,y)[1] + img.at<Vec3b>(x,y)[2])/3);
				}
			}
			int min = *min_element(push.begin(),push.end());
			for(int x=i-1;x<=i+1;x++){
				for(int y=j-1;y<=j+1;y++){
					for(int c=0;c<3;c++){
						new_img_eros.at<Vec3b>(x,y)[c] = min;
					}
				}
			}
		}
	}
	
	namedWindow("erosion",CV_WINDOW_AUTOSIZE);
	imshow("erosion",new_img_eros);

	return new_img_eros;
}

Mat dialation(Mat img){
	Mat new_img_dial = img.clone();
	int r = img.rows;
	int c = img.cols;
	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			vector<int> push;
			for(int x=i-1;x<=i+1;x++){
				for(int y=j-1;y<=j+1;y++){
					push.push_back((img.at<Vec3b>(x,y)[0] + img.at<Vec3b>(x,y)[1] + img.at<Vec3b>(x,y)[2])/3);
				}
			}
			int max = *max_element(push.begin(),push.end());
			for(int x=i-1;x<=i+1;x++){
				for(int y=j-1;y<=j+1;y++){
					for(int c=0;c<3;c++){
						new_img_dial.at<Vec3b>(x,y)[c] = max;
					}
				}
			}
		}
	}
	
	namedWindow("dialation",CV_WINDOW_AUTOSIZE);
	imshow("dialation",new_img_dial);

	return new_img_dial;
}

int main(){
	namedWindow("input",CV_WINDOW_AUTOSIZE);
	
	imshow("input",img);
	erosion(img);
	waitKey(0);
	

	imshow("input",img2);
	dialation(img2);
	waitKey(0);

	imshow("input",img3);
	erosion(img3);
	waitKey(0);

	imshow("input",img4);
	Mat dial = dialation(img4);
	Mat temp = erosion(dial);
	erosion(temp);
	waitKey(0);
	

	return 0;
}