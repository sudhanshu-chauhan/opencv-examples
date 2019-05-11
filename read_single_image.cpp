#include<iostream>
#include<cstdlib>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){
	Mat image = imread("/home/sud/pictures/gerwinski-gnu-head.png");
	cout<<image[0]<<endl;
	return 0;
}

