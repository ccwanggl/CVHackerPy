#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::Mat r = cv::Mat(10, 3, CV_8UC3);
  cv::randu(r, cv::Scalar::all(0), cv::Scalar::all(0));

  std::cout << "Opencv style" << std::endl
            << r << ";" << std::endl
            << std::endl;
  std::cout << "Python style" << std::endl
            << cv::format(r, cv::Formatter::FMT_PYTHON) << ";" << std::endl
            << std::endl;
  std::cout << "CSV style" << std::endl
            << cv::format(r, cv::Formatter::FMT_CSV) << ";" << std::endl
            << std::endl;
  std::cout << "Numpy style" << std::endl
            << cv::format(r, cv::Formatter::FMT_NUMPY) << ";" << std::endl
            << std::endl;
  std::cout << "C style" << std::endl
            << cv::format(r, cv::Formatter::FMT_C) << ";" << std::endl
            << std::endl;

  return 0;
}
