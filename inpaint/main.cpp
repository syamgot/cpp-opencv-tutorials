#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


// ----------------------------------------
//
// 消したい対象を含むマスクをかけないと修復が不足する
// input radius は大きい方が綺麗に消してくれるが、処理速度に影響する
// Navier-Stokes と Alexandru Telea の差はよく分からない
//
// ----------------------------------------

int main(int argc, const char *argv[]) {

	// 変数定義
	Mat src, mask1, mask2, mask3, mask4, dst;

	// 画像の準備
	src  = imread("./data/image.jpg");
	mask1 = imread("./data/mask1.bmp", 0);
	mask2 = imread("./data/mask2.bmp", 0);
	mask3 = imread("./data/mask3.bmp", 0);
	mask4 = imread("./data/mask4.bmp", 0);
	if(src.empty() || mask1.empty() || mask2.empty() || mask3.empty() || mask4.empty()) {
		return -1;
	}

	// 
	double inpaintRadius = 10;

	// 
	imshow("src", src);

	// 線の太さ
	inpaint(src, mask1, dst, inpaintRadius, INPAINT_NS);
	imshow("inpaint1", dst); // より細い
	inpaint(src, mask2, dst, inpaintRadius, INPAINT_NS);
	imshow("inpaint2", dst); // 同じ太さ
	inpaint(src, mask3, dst, inpaintRadius, INPAINT_NS);
	imshow("inpaint3", dst) // より太い;

	// パラメータ
	inpaint(src, mask4, dst, inpaintRadius, INPAINT_NS);
	imshow("mask4 INPAINT_NS", dst);
	inpaint(src, mask4, dst, inpaintRadius, INPAINT_TELEA);
	imshow("mask4 INPAINT_TELEA", dst);
	inpaint(src, mask4, dst, inpaintRadius / 5, INPAINT_NS);
	imshow("mask4 INPAINT_NS r2", dst);
	inpaint(src, mask4, dst, inpaintRadius * 50, INPAINT_NS);
	imshow("mask4 INPAINT_NS r50", dst);

	// 出力&キー受付
	waitKey();

	return 0;

}
