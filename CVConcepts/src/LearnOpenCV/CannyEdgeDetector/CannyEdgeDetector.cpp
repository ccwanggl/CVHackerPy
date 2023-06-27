#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>


int main(int argc, char **argv) {
  cv::Mat img_rgb;
  cv::Mat img_gry;
  cv::Mat img_cny;

  cv::namedWindow("Gray");
  cv::namedWindow("Canny");

  img_rgb = cv::imread("../../Data/lena.jpg");

  cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
  cv::imshow("Gray", img_gry);

  cv::Canny(img_gry, img_cny, 10, 100, 3, true);
  cv::imshow("Canny", img_cny);

  cv::waitKey(0);
  return 0;
}
