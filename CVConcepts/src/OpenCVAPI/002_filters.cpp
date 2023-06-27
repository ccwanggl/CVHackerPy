#include <opencv2/opencv.hpp>

int main()
{
	auto img = cv::imread("../../../DataSet/lena.jpg");
	cv::imshow("Lena", img);
	cv::waitKey(0);
}
