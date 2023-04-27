#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  cv::Mat img;

  if (argc > 2) {
    img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  } else {
    return -1;
  }

  if (img.empty()) {
    std::cout << "Could not find file" << std::endl;
  }

  cv::namedWindow("Lena", cv::WINDOW_AUTOSIZE);
  cv::imshow("lena", img);

  cv::waitKey(0);
  cv::destroyWindow("Lena");

  return 0;
}
