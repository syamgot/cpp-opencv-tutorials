#include "opencv2/opencv.hpp"

int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat im, mask, dst;

	// 画像の準備
	im 	 = cv::imread("./data/image.jpg");
	mask = cv::imread("./data/mask.jpg");

	// マスク
	dst = im.clone();
	cv::bitwise_and(im, mask, dst);

	// 出力&キー受付
	cv::imshow("out", dst);
	cv::waitKey();

	return 0;

}
