#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using namespace cv;

Mat img_gray = imread("/home/akash/Desktop/coding/IP/openCV/img.png",0);

Mat img = img_gray > 200;

Mat visited(img.rows,img.cols,CV_8UC1,Scalar(0));

Mat visited_bfs(img.rows,img.cols,CV_8UC1,Scalar(0));

void DFS(int x,int y)
{
	stack<pair<int,int> > s;
	
	s.push(make_pair(x,y));
	visited.at<uchar>(x,y) = 255; 

	while(!s.empty()){
		std::pair<int,int> p = s.top();
		s.pop();
		int fi = p.first;
		int se = p.second;
		for(int i=fi-1;i<=fi+1;i++){
			for(int j=se-1;j<=se+1;j++){
				if(img.at<uchar>(i,j) == 0 && visited.at<uchar>(i,j) == 0){
					visited.at<uchar>(i,j) = 255;
					s.push(make_pair(i,j));
				}
			}
		}
	}
}

void BFS(int x,int y){
	queue<pair<int,int> > q;

	q.push(make_pair(x,y));
	visited_bfs.at<uchar>(x,y) = 255;

	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();

		int f = p.first;
		int s = p.second;

		for(int i=f-1;i<=f+1;i++){
			for(int j=s-1;j<=s+1;j++){
				if(!visited_bfs.at<uchar>(i,j) && img.at<uchar>(i,j) == 0){
					visited_bfs.at<uchar>(i,j) = 255;
					q.push(make_pair(i,j));
				}
			}
		} 
	}
}

int main(){
	int r = img.rows;
	int c = img.cols;
	
	int count = 0,count_bfs = 0;

	for(int x=1;x<r-1;x++){
		for(int y=1;y<c-1;y++){
			if(img.at<uchar>(x,y) == 0){
				if(visited.at<uchar>(x,y) == 0){
					DFS(x,y);
					count++;
				}
				if(visited_bfs.at<uchar>(x,y) == 0){
					BFS(x,y);
					count_bfs++;
				}
			}
		}
	}

	cout << count << endl;
	cout << count_bfs << endl;

	
	namedWindow("window",CV_WINDOW_AUTOSIZE);
	imshow("window",img);
	waitKey(0);


	return 0;
}