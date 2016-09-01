#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	Mat src, dst;


	// ----------------------------------------
	// 3チャンネル
	// 

	src = imread("./data/image.jpg");

	// cv::Mat::at 
	dst = src.clone();
	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			// ネガポジ反転
			dst.at<Vec3b>(y,x)[0] = ~dst.at<Vec3b>(y,x)[0]; // B
			dst.at<Vec3b>(y,x)[1] = ~dst.at<Vec3b>(y,x)[1]; // G
			dst.at<Vec3b>(y,x)[2] = ~dst.at<Vec3b>(y,x)[2]; // R
		}
	}
	imshow("out", dst);
	waitKey();

	// cv::MatIterator_
	dst = src.clone();
	MatIterator_<Vec3b> it 		= dst.begin<Vec3b>();
	MatIterator_<Vec3b> it_end 	= dst.end<Vec3b>();
	for(; it != it_end; it++) {
		// シャッフル
		int b = (*it)[0]; int g = (*it)[1]; int r = (*it)[2];
		(*it)[0] = r;
		(*it)[1] = b;
		(*it)[2] = g;
	}
	imshow("out", dst);
	waitKey();

	// data
	dst = src.clone();
	for(int y = 0; y < dst.rows; y++){
		for(int x = 0; x < dst.cols; x++){
			for(int c = 0; c < dst.channels(); c++){
				int i = y * dst.step + x * dst.elemSize() + c;
				dst.data[i] = ~dst.data[i];
			}
		}
	}
	imshow("out", dst);
	waitKey();

	// ポインタ
	dst = src.clone();
	for(int y = 0; y < dst.rows; y++){
		for(int x = 0; x < dst.cols; x++){
			Vec3b *ptr = dst.ptr<Vec3b>(y);
			// シャッフル
			int b = (*ptr)[x*3+0]; 
			int g = (*ptr)[x*3+1]; 
			int r = (*ptr)[x*3+2];
			(*ptr)[x*3+0] = g;
			(*ptr)[x*3+1] = b;
			(*ptr)[x*3+2] = r;
		}
	}
	imshow("out", dst);
	waitKey();



	// ----------------------------------------
	// 1チャンネル
	// 

	src = imread("./data/image.jpg", 0);
	dst = src.clone();
	for(int y = 0; y < dst.rows; y++){
		for(int x = 0; x < dst.cols; x++){
			dst.at<uchar>(y,x) = ~dst.at<uchar>(y,x);
		}
	}
	imshow("out", dst);
	waitKey();


	return 0;

}
