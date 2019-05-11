#include<iostream>
#include<cstdlib>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){
	Mat a = Mat::eye(Size(3,2), CV_32F);
	cout<<a<<endl;
	return 0;
}
