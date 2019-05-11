#include<iostream>
#include<cstdlib>

#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


int get_random_number(){
	typedef boost::mt19937 RNGType;
	RNGType rng;
	boost::uniform_int<> random_int(0, 255);
	boost::variate_generator< RNGType, boost::uniform_int<> > pixel_randomizer(rng, random_int);
	return pixel_randomizer();
};

Vec3b return_random_pixel(){
	typedef boost::mt19937 RNGType;
        RNGType rng;
        boost::uniform_int<> random_int(0, 255);
        boost::variate_generator< RNGType, boost::uniform_int<> > pixel_randomizer(rng, random_int);

	Vec3b random_pixel;
	random_pixel[0] = pixel_randomizer();
	random_pixel[1] = pixel_randomizer();
	random_pixel[2] = pixel_randomizer();
	return random_pixel;
};

int main(){
	Mat abc(301, 260, CV_8UC3, Scalar(0,0,0));
	for(int i = 0; i < abc.rows; i++){
		for(int j =0; j < abc.cols; j++){
			abc.at<Vec3b>(i, j) = return_random_pixel();
		}		
	}
	imwrite("in.jpg",abc);
	return 0;
}
