#include<iostream>
#include<string>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

const char* keys =
{
"{help h usage ? | | print this message}"
"{@video | | Video file, if not defined try to use webcamera}"
};

int main(int argc, char *argv[]){
	CommandLineParser parser(argc, argv, keys);
	parser.about("image reader v1.0.0");
	if(parser.has("help")){
		parser.printMessage();
		return 0;
	}
	String image_file = parser.get<String>(0);
	if(!parser.check()){
		parser.printErrors();
		return 0;
	}
	Mat img = imread(image_file);
	for(int i = 0; i<img.rows; i++){
		for(int j =0; j<img.cols; j++){
			Vec3b bgr_pixel = img.at<Vec3b>(i, j);
			cout<<bgr_pixel<<"\t";
		}
	}
	//cout<<img<<endl;
	return 0;
}
