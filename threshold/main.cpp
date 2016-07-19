#include "opencv2/opencv.hpp"

int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat src, dst;

	// 画像の準備
	src = cv::imread("./data/image.jpg");
	if(src.empty()) {
		return -1;
	}

	// 2値化
	cv::cvtColor(src, dst, cv::COLOR_RGB2GRAY);
	cv::threshold(dst, dst, 0, 255, cv::THRESH_BINARY|cv::THRESH_OTSU);

	// 出力&キー受付
	cv::imshow("out", dst);
	cv::waitKey();

	return 0;

}
