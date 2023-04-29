#include "opencv2/core/traits.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ostream>

int main() {
  // NOTE: cv::Mat constructors that do not copy data
  /*
  cv::mat
  cv::Mat(int rows, int cols, int type);
  cv::Mat(int rows, int cols, int type, const Scalar &s);
  cv::Mat(int rows, int cols, int type, void* data, size_t step = AUTO_STEP);
  cv::Mat(cv::Size sz, int type);
  cv::Mat(cv::Size sz, int type, const cv::Scalar& s);
  cv::Mat(cv::Size sz, int type, void* data, size_t step = AUTO_STEP);
  cv::Mat(int ndims, const int* sizes, int type);
  cv::Mat(int ndims, const int* sizes, int type, const cv::Scalar& s);
  cv::Mat(int ndims, const int* sizes, int type, void* data, size_t step =
  AUTO_STEP);
  */

  cv::Mat M(2, 2, CV_8UC3, cv::Scalar(0, 0, 225));
  std::cout << "M = " << std::endl
            << " " << cv::format(M, cv::Formatter::FMT_NUMPY) << std::endl
            << "step(The first row bytes): " << M.step << std::endl
            << "step[0](The first row bytes): " << M.step[0] << std::endl
            << "step[1](The first element bytes): " << M.step[1] << std::endl
            << "step1(0)(The first row element channel count): " << M.step1(0)
            << std::endl
            << "step1(1)(The element channel count): " << M.step1(1)
            << std::endl
            << std::endl;

  // NOTE: PhotoType:
  cv::Mat mat;
  mat.create(3, 10, CV_8UC3);
  mat.setTo(cv::Scalar(1.0, 2.0, 3.0));
  std::cout << "mat = " << std::endl
            << " " << cv::format(mat, cv::Formatter::FMT_PYTHON) << std::endl
            << "step is " << std::endl
            << std::endl;

  // NOTE: cv::Mat constructors that copy data from other cv::Mats

  /*
   cv::Mat(const Mat& mat);
   cv::Mat(const Mat& mat, const cv::Range& rows, const cv::Range& cols);
   cv::Mat(const Mat& mat, const cv::Rect& roi);
   cv::Mat(const Mat& mat, const cv::Range* ranges);
   cv::Mat(const cv::MatExpr& expr);
    */

  // NOTE: cv::Mat template constructors
  /*
   cv::Mat(const cv::Vec<T,n>& vec, bool copyData= true);
   cv::Mat(const cv::Matx<T,m,n>& vec, bool copyData=true);
   cv::Mat(const std::vector<T>& vec, bool copyData=true);
    */

  // NOTE: Static functions that create cv::Mat
  /*
  cv::Mat::zeros(rows, cols, type);
  cv::Mat::ones(rows, cols, type);
  cv::mat::eye(rows, cols, type);
  */

  cv::Mat m1 = cv::Mat::eye(10, 10, CV_32FC2);
  printf("Element (3,3) is (%f, %f)\n", m1.at<cv::Vec2f>(3, 3)[0],
         m1.at<cv::Vec2f>(3, 3)[1]);

#if 0
  cv::Mat m2 = cv::Mat::eye(10, 10, cv::DataType<cv::Complexf>::generic_type);
  printf("Element (3,3) is (%f, %f)\n", m2.at<cv::Complexf>(3, 3).re,
         m2.at<cv::Complexf>(3, 3).im);
#endif

  return 0;
}
