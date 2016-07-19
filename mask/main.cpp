#include "opencv2/opencv.hpp"

int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat src, mask, dst;

	// 画像の準備
	src  = cv::imread("./data/image.jpg");
	mask = cv::imread("./data/mask.jpg");
	if(src.empty() || mask.empty()) {
		return -1;
	}

	// マスク
	dst = src.clone();
	cv::bitwise_and(src, mask, dst);

	// 出力&キー受付
	cv::imshow("out", dst);
	cv::waitKey();

	return 0;

}
