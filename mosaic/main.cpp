#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat src, dst;

	// 画像の準備
	src  = cv::imread("./data/image.jpg");
	if(src.empty()) {
		return -1;
	}

	// モザイク
	resize(src, dst, Size(), 0.1, 0.1); // 1/10に縮小
	resize(dst, dst, Size(), 10, 10, CV_INTER_NN); // 10倍に拡大

	// 出力&キー受付
	cv::imshow("out", dst);
	cv::waitKey();

	return 0;

}
