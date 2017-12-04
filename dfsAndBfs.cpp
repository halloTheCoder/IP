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
#include <numeric>
#include <cmath>

using namespace std;
using namespace cv;

Mat img_gray = imread("/home/akash/Desktop/coding/IP/openCV/img.png",0);

Mat img = img_gray > 200;

Mat visited(img.rows,img.cols,CV_8UC1,Scalar(0));

Mat visited_bfs(img.rows,img.cols,CV_8UC1,Scalar(0));

vector<pair<int,int> > corner[3];

bool Compare(pair<int,int> p1,pair<int,int> p2){
	return p1.first > p2.first;
}

void DFS(int x,int y,int count)                //DONT DO DFS USING RECURSION SINCE IF SIZE OF IMAGE IS LARGE SAY 1000*1000 THEN USING RECURSION HEAP MEMORY ALLOCATION WILL FAIL
{
	stack<pair<int,int> > s;
	
	s.push(make_pair(x,y));
	visited.at<uchar>(x,y) = 255; 

	vector<pair<int,int> > cor_l,cor_r_up;

	while(!s.empty()){
		std::pair<int,int> p = s.top();
		s.pop();
		int fi = p.first;
		int se = p.second;
		for(int i=fi-1;i<=fi+1;i++){
			for(int j=se-1;j<=se+1;j++){
				if(i == fi && j == se)
					continue;

				if(img.at<uchar>(i,j) == 255){
					if(i == x-1){
						cor_r_up.push_back(make_pair(j,i));
					}

					if(j == y-1){
						cor_l.push_back(make_pair(i,j));
					}
				}
				
				if(img.at<uchar>(i,j) == 0 && visited.at<uchar>(i,j) == 0){
					visited.at<uchar>(i,j) = 255;
					s.push(make_pair(i,j));
				}
			}
		}

		sort(cor_r_up.begin(),cor_r_up.end(),Compare);
		sort(cor_l.begin(),cor_l.end(),Compare);

		int max_r_up = cor_r_up[cor_r_up.size()-1].first;
		int max_l = cor_l[cor_l.size()-1].first;

		corner[count].push_back(make_pair(x,max_r_up));
		corner[count].push_back(make_pair(max_l,y));
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

int calcDist(pair<int,int> p1,pair<int,int> p2){
	return std::sqrt(std::pow(p1.first-p2.first,2) + std::pow(p1.second-p2.second,2));
}

void calcMaxDist(){
	vector<pair<int,int> > centroid;
	
	int max_dist = -1;
	
	for(int i=0;i<3;i++){
		centroid.push_back(make_pair((corner[i][0].first+corner[i][1].first+corner[i][2].first)/3,(corner[i][0].first+corner[i][1].first+corner[i][2].first)/3));
	}
	max_dist = max(max_dist,calcDist(centroid[0],centroid[1]));
	max_dist = max(max_dist,calcDist(centroid[1],centroid[2]));
	max_dist = max(max_dist,calcDist(centroid[0],centroid[2]));

	cout << max_dist << endl;
}

int main(){
	int r = img.rows;
	int c = img.cols;
	
	int count = 0,count_bfs = 0;

	for(int x=1;x<r-1;x++){
		for(int y=1;y<c-1;y++){
			if(img.at<uchar>(x,y) == 0){              //IS IT NECESSARY TO WRITE TWOIF STATEMENTS
				
				corner[count].push_back(make_pair(x,y));

				if(visited.at<uchar>(x,y) == 0){
					DFS(x,y,count);
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

	calcMaxDist();
	
	namedWindow("window",CV_WINDOW_AUTOSIZE);
	imshow("window",img);
	waitKey(0);


	return 0;
}