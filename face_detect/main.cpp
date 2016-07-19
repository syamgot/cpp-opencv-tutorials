#include "opencv2/opencv.hpp"

int main(int argc, const char *argv[]) {

	// 変数定義
	cv::Mat src, gray, dst;
	cv::CascadeClassifier cascade;	
	std::vector<cv::Rect> faces;
	int keycode;

	// カスケード分類器の準備
	if (!cascade.load("./data/haarcascade_frontalface_alt.xml")) {
		return -1;
	}

	// カメラの準備
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	// フレームアップデート処理
	while (cap.read(src)){

		// 顔検出
		// - グレースケール化
		// - カスケード分類器で顔の矩形を取得
		// - 矩形を囲む
		dst = src.clone();
		cvtColor(src, gray, CV_RGB2GRAY);
		cascade.detectMultiScale(gray, faces, 1.2, 2, CV_HAAR_SCALE_IMAGE, cv::Size(50, 50));
		for (int i = 0; i < faces.size(); i++){
			rectangle(src, cv::Point(faces[i].x,faces[i].y),cv::Point(faces[i].x + faces[i].width,faces[i].y + faces[i].height),cv::Scalar(0,255,0),3,CV_AA);
		}

		// 出力
		imshow("out", src);

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
