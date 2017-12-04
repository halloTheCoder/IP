#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace cv;


int medianBlurUtil(Mat img,int i,int j){
	vector<int> vec;

	for(int x=i-1;x<=i+1;x++){
		for(int y=j-1;y<=j+1;y++){
			if(x==i && y==j)
				continue;
			vec.push_back(img.at<uchar>(x,y));
		}
	}
	sort(vec.begin(),vec.end());

	return (int)(vec[4] + vec[5])/2;
}

void medianBlur(Mat img){
	Mat new_img = img.clone();

	int r = img.rows;
	int c = img.cols;
	
	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			new_img.at<uchar>(i,j) = medianBlurUtil(img,i,j);
		}
	}

	namedWindow("MEDIAN_BLUR",CV_WINDOW_AUTOSIZE);
	imshow("MEDIAN_BLUR",new_img);

}

int meanBlurUtil(Mat img,int i,int j){
	vector<int> vec;

	for(int x=i-1;x<=i+1;x++){
		for(int y=j-1;y<=j+1;y++){
			if(x==i && y==j)
				continue;
			vec.push_back(img.at<uchar>(x,y));
		}
	}
	return (accumulate(vec.begin(),vec.end(),0) / vec.size());
}

void meanBlur(Mat img){
	Mat new_img = img.clone();

	int r = img.rows;
	int c = img.cols;
	
	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			new_img.at<uchar>(i,j) = meanBlurUtil(img,i,j);
		}
	}

	namedWindow("MEAN_BLUR",CV_WINDOW_AUTOSIZE);
	imshow("MEAN_BLUR",new_img);

}

int gaussianBlurUtil(Mat img,int i,int j){
	return img.at<uchar>(i-1,j-1) + 2*img.at<uchar>(i-1,j) + img.at<uchar>(i-1,j+1) + 2*img.at<uchar>(i,j-1)
		   + 4*img.at<uchar>(i,j) + 2*img.at<uchar>(i,j+1) + img.at<uchar>(i+1,j-1) + 2*img.at<uchar>(i+1,j) + img.at<uchar>(i+1,j+1);
}

void gaussianBlur(Mat img){
	Mat new_img = img.clone();

	int r = img.rows;
	int c = img.cols;
	
	for(int i=1;i<r-1;i++){
		for(int j=1;j<c-1;j++){
			new_img.at<uchar>(i,j) = gaussianBlurUtil(img,i,j)/16;
		}
	}

	namedWindow("GAUSSIAN_BLUR_OWN",CV_WINDOW_AUTOSIZE);
	imshow("GAUSSIAN_BLUR_OWN",new_img);

}

int main(){
	Mat img = imread("/home/akash/Desktop/coding/IP/openCV/veg.jpg",0);

	medianBlur(img);
	
	meanBlur(img);

	gaussianBlur(img);             

	Mat dst = img.clone();
	GaussianBlur(img,dst,Size(3,3),0,0);

	namedWindow("GAUSSIAN_BLUR",CV_WINDOW_AUTOSIZE);
	imshow("GAUSSIAN_BLUR",dst);

	dst = img.clone();

	bilateralFilter(img,dst,5,80,80);

	namedWindow("BILATERAL_FILTER",CV_WINDOW_AUTOSIZE);
	imshow("BILATERAL_FILTER",dst);

	namedWindow("input",CV_WINDOW_AUTOSIZE);
	imshow("input",img);

	waitKey(0);

	return 0;
}