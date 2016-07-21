#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
	cv::Mat src;
	src = cv::imread("./data/image.jpg");

	// cv::Mat::at 
	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			(src.at<cv::Vec<unsigned char,3 > >(y,x))[0] = 255;
			(src.at<cv::Vec<unsigned char,3 > >(y,x))[1] = 255;
			(src.at<cv::Vec<unsigned char,3 > >(y,x))[2] = 255;
		}
	}

	// cv::MatIterator_
	cv::MatIterator_<cv::Vec<unsigned char, 3> > it 	= src.begin<cv::Vec<unsigned char, 3> >();
	cv::MatIterator_<cv::Vec<unsigned char, 3> > it_end = src.end<cv::Vec<unsigned char, 3> >();
	for(; it != it_end; it++) {
		(*it)[0] = 255;
		(*it)[1] = 255;
		(*it)[2] = 255;
	}

	return 0;

}
