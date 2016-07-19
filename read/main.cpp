#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
	cv::Mat src;
	src = cv::imread("./data/image.jpg", cv::IMREAD_COLOR); 	// カラー(3チャンネル)で読み込み. bit数は未指定. デフォルト. 1
	src = cv::imread("./data/image.jpg", cv::IMREAD_GRAYSCALE); // グレースケール画像(3チャンネル)で読み込み. 8bit画像. 0
	src = cv::imread("./data/image.jpg", cv::IMREAD_UNCHANGED);	// カラー(RGBAの4チャンネル)で読み込み. 8bit画像. カラーかグレーかは自動判定. -1

	// 読み込み判定
	src = cv::imread("./data/unknown.jpg");
	if (src.empty()) {
		printf("%s\n", "画像が読み込めなかった");
	}
}
