#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char *argv[]) {

	Mat im = Mat::zeros(Size(300,300), CV_32FC3);

	line(im, Point( 50, 50), Point(250, 60), Scalar(  0,  0,200), 1, 4);
	line(im, Point( 50, 70), Point(250, 80), Scalar(  0,200,  0), 1, 8);
	line(im, Point( 50, 90), Point(250,100), Scalar(200,  0,  0), 1, CV_AA);

	line(im, Point( 50,150), Point(250,160), Scalar(  0,  0,200),10, 4);
	line(im, Point( 50,170), Point(250,180), Scalar(  0,200,  0),10, 8);
	line(im, Point( 50,190), Point(250,200), Scalar(200,  0,  0),10, CV_AA);

	cv::imshow("out", im);
	cv::waitKey();

	return 0;

}
