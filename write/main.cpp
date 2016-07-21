#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
	cv::Mat src;
	src = cv::imread("./data/image.jpg");
	cv::imwrite("./data/out.jpg", src);
}
