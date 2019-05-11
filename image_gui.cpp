#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;

//const int CV_GUI_NORMAL = Ox10;

int main(int argc, const char** argv){
	Mat toys = imread("./toys.jpg");
	Mat profile = imread("./profile.jpg");

	namedWindow("my toys", CV_GUI_NORMAL);
	namedWindow("my profile", WINDOW_AUTOSIZE);

	moveWindow("my toys", 10, 10);
	moveWindow("my profile", 520, 10);

	imshow("my toys", toys);
	imshow("my profile", profile);

	resizeWindow("my toys", 1024, 768);

	waitKey(0);

	destroyWindow("my toys");
	destroyWindow("my profile");

	return 0;
}