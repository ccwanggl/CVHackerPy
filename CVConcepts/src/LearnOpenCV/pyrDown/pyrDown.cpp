#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  cv::Mat larger, medium;
  cv::namedWindow("larger");
  cv::namedWindow("medium");

  larger = cv::imread("../Data/lena.jpg");
  cv::imshow("larger", larger);

  cv::pyrDown(larger, medium);
  cv::imshow("medium", medium);
  cv::waitKey(0);

  return 0;
}
