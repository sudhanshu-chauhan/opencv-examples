/*
takes video file as parameter and
split video to the corresponding
frames into jpg images

@author sudhanshu singh chauhan
*/

#include<iostream>
#include<string>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace cv;

//command line argument keys
const char* keys = 
{
	"{help h usage? || print this message}"
	"{@video || Video File, if not defined then exit program}"
};

int main(int argc, char **argv){
	//parser object to process command line parameters
	CommandLineParser parser(argc, argv, keys);
	parser.about("split_video_frames v1.0.0");
	
	if(parser.has("help")){
		parser.printMessage();
		return 0;
	}
	//getting video file name in command
	//line parameter
	string videoFile = parser.get<String>(0);
	if(!parser.check()){
		parser.printErrors();
		return 0;
	}	
	VideoCapture cap;  //to capture the video file
	if(videoFile != ""){
		cap.open(videoFile);	
	}
	else{
		cout<<"no video file provided!.."<<endl;
		cout<<"exiting.. bye"<<endl;
	}
	if(!cap.isOpened()){
		return -1;
	}
	int frame_count = 0;
	//processing each frame and
	//saving it as jpg image file
	for(;;){
		Mat frame;
		cap >> frame;
		string file_name = "frame";
		if(!frame.empty()){
			file_name += boost::lexical_cast<string>(frame_count);
			file_name += ".jpg";
			imwrite(file_name, frame);
		}
		//break the loop when no more 
		//frames are left
		else{
			break;
		}
		frame_count++;
	}
	//release the video capture object when done
	//so that program doesnt block anymore
	cap.release();
	return EXIT_SUCCESS;
}
