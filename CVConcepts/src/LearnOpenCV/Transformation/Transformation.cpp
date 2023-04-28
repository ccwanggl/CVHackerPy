#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

void blur(const cv::Mat &img) {
  cv::namedWindow("source");
  cv::namedWindow("target");

  cv::imshow("source", img);

  cv::Mat target;
  cv::GaussianBlur(img, target, cv::Size(5, 5), 3, 3);
  cv::imshow("target", target);

  cv::waitKey(0);
}

int main(int argc, char **argv) {
  cv::Mat img = cv::imread("../Data/lena.jpg");
  blur(img);

  return 0;
}
