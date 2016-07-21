#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"


int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat src, dst;
	int keycode;
    cv::Ptr<cv::BackgroundSubtractorMOG2> bgsub;

	// カメラの準備
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	// 混合正規分布による背景モデルを作成
	bgsub = cv::createBackgroundSubtractorMOG2();

	// フレームアップデート処理
	while (cap.read(src)){

		//
		bgsub->apply(src, dst);

		// 出力
		imshow("out", dst);

		// キー受付
		keycode = cv::waitKey(1000/60);
		if (keycode > 0) {
			// Escかqが入力されたら終了
			if (keycode == 27 || keycode == 113){
				break;
			}
		}
	}

	// キャプチャを解放
	cap.release();

	return 0;

}
