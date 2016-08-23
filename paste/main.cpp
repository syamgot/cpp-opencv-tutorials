#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char *argv[]) {

	Mat src1 = imread("./data/image.jpg");
	Mat src2 = imread("./data/image2.jpg");
	Mat dst(Size(src1.cols*2, src2.rows*2), CV_8UC3);
	dst = Scalar(255,255,255);

	Mat roi1(dst, Rect(0+30, 0+30, src1.cols, src1.rows));
	Mat roi2(dst, Rect(src1.cols-30, src1.rows-30, src2.cols, src2.rows));

	src1.copyTo(roi1);
	src2.copyTo(roi2);

	imshow("out", dst);
	waitKey();
	return 0;

}
