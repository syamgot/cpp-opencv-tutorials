#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, const char *argv[]) {

	// 変数定義
	Mat src, dst;
	int keycode;
	int th = 50; 							// トラックバーの値
	string windowName = "Trackbar Test"; 	// ウィンドウ名

	// 画像をグレースケールで読込
	src = imread("./data/image.jpg", 0);
	if (src.empty()) {
		return -1;
	}

	// ウィンドウ作成
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	createTrackbar("threshold bar", windowName, &th, 255); // トラックバーを作成

	// 
	while(1) {

		// 2値化して表示
		threshold(src, dst, 0, th, cv::THRESH_BINARY | cv::THRESH_OTSU);
		imshow(windowName, dst);

		// キー受付
		keycode = cv::waitKey(1000/60);
		if (keycode > 0) {
			// Escかqが入力されたら終了
			if (keycode == 27 || keycode == 113){
				break;
			}
		}

	}


	return 0;

}
