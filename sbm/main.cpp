#include "opencv2/opencv.hpp"
#include "opencv2/calib3d.hpp" 

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {

	// window準備
	string windowName = "out";
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);

	// 視差サイズ
	int s = 0, n = 0;
	createTrackbar("ndisparities", windowName, &n, 5);
	createTrackbar("SADWindowSize", windowName, &s, 5);

	int ndisparities; // 視差サイズ
	int SADWindowSize; // 平均化Windowサイズ

	Mat srcL, srcR, img16S, img8U;
	int keycode;

	srcL   = imread("./data/tsucuba_left.png", 0);
	srcR   = imread("./data/tsucuba_right.png", 0);

	imshow("L", srcL);
	imshow("R", srcR);

 	img16S = Mat( srcL.rows, srcL.cols, CV_16S );
 	img8U  = Mat( srcL.rows, srcL.cols, CV_8UC1 );

	while(1) {

		// 視差サイズとブロックサイズを作成
		ndisparities  = 16*(n+1);
		SADWindowSize = 9+s*6;

		// BM法でステレオ対応点探索
		Ptr<StereoBM> sbm = StereoBM::create( ndisparities, SADWindowSize );
		sbm->compute( srcL, srcR, img16S );
	
		// imshowのために視差データを8bit変換
		double minVal; double maxVal;
		minMaxLoc( img16S, &minVal, &maxVal );
		img16S.convertTo( img8U, CV_8UC1, 255/(maxVal - minVal));

		// おまけ
		putText(img8U, to_string(ndisparities), Point(50,50), FONT_HERSHEY_SIMPLEX, 1, 255, 2, CV_AA);
		putText(img8U, to_string(SADWindowSize), Point(50,100), FONT_HERSHEY_SIMPLEX, 1, 255, 2, CV_AA);

		// 出力
		imshow(windowName, img8U);

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
