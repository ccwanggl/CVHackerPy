#include <iostream> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

int main()
{
	std::cout << cv::getVersionString() << '\n';
	auto img = cv::imread("lena.jpg", cv::IMREAD_COLOR);
	cv::imshow("lena", img);
	cv::waitKey(0);

	return 0;
}
