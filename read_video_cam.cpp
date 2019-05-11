/*
takes video file as parameter
and plays it, if video not
provided then tries to play from
the web camera

@author sudhanshu singh chauhan
*/
#include<iostream>
#include<string>
#include<sstream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

//command line argument keys
const char* keys =
{
	"{help h usage? || print this message}"
	"{@video  || Video File, if not defined, try to use webcamera}"
};

int main(int argc, char **argv){
	//parser object to process command line params
	CommandLineParser parser(argc, argv, keys);
	parser.about("read_video_cap v1.0.0");
	
	if(parser.has("help")){
		parser.printMessage();
		return 0;
	}
	//getting video file name from parser
	String videoFile = parser.get<String>(0);
	if(!parser.check()){
		parser.printErrors();
		return 0;
	}
	VideoCapture cap;	//to capture video file
	if(videoFile != "")
		cap.open(videoFile);
	else
		cap.open(0);
	if(!cap.isOpened())
		return -1;
	namedWindow("Video", 1);
	//process each frame and dislpay it
	for(;;){
		Mat frame ;
		cap >> frame;	//get a new frame from camera
		//check for empty frame
		if(!frame.empty())
			imshow("Video", frame);
		if(waitKey(30) >= 0) break;
	}
	cap.release();	//relase video capture object
	return 0;

}


