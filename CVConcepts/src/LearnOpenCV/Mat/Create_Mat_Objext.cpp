#undef OPENCV_TRAITS_ENABLE_DEPRECATED

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/traits.hpp>
#include <ostream>


int main() {
  // NOTE: cv::Mat constructors that do not copy data
  /*
  cv::mat
  cv::Mat(int rows, int cols, int type);
  cv::Mat(int rows, int cols, int type, const Scalar &s);
  cv::Mat(int rows, int cols, int type, void* data, size_t step = AUTO_STEP);
  */

  cv::Mat mat1(2, 2, CV_8UC3);

  cv::Mat mat2(2, 2, CV_8UC3, cv::Scalar(0, 0, 225));
  std::cout << "M = " << std::endl
            << " " << cv::format(mat2, cv::Formatter::FMT_PYTHON) << std::endl
            << "step(The first row bytes): " << mat2.step << std::endl
            << "step[0](The first row bytes): " << mat2.step[0] << std::endl
            << "step[1](The first element bytes): " << mat2.step[1] << std::endl
            << "step1(0)(The first row element channel count): "
            << mat2.step1(0) << std::endl
            << "step1(1)(The element channel count): " << mat2.step1(1)
            << std::endl
            << std::endl;

  char arr[] = {1, 2, 4};
  cv::Mat mat3(2, 2, CV_8UC3, arr);
  std::cout << "mat3 = " << std::endl
            << " " << cv::format(mat3, cv::Formatter::FMT_PYTHON) << std::endl
            << "step(The first row bytes): " << mat3.step << std::endl
            << "step[0](The first row bytes): " << mat3.step[0] << std::endl
            << "step[1](The first element bytes): " << mat3.step[1] << std::endl
            << "step1(0)(The first row element channel count): "
            << mat3.step1(0) << std::endl
            << "step1(1)(The element channel count): " << mat3.step1(1)
            << std::endl
            << std::endl;

  cv::Mat matt1;
  matt1.create(3, 10, CV_32FC3);
  matt1.setTo(cv::Scalar(1.0, 2.0, 3.0));
  std::cout << "matt1 = " << std::endl
            << cv::format(matt1, cv::Formatter::FMT_PYTHON) << std::endl
            << std::endl
            << std::endl;

  /*
  cv::Mat(cv::Size sz, int type);
  cv::Mat(cv::Size sz, int type, const cv::Scalar& s);
  cv::Mat(cv::Size sz, int type, void* data, size_t step = AUTO_STEP);
  */

  cv::Size size(2, 2);
  cv::Mat matsize1(size, CV_8UC3);

  cv::Mat matsize2(size, CV_8UC3, cv::Scalar(0, 0, 225));
  std::cout << "M = " << std::endl
            << " " << cv::format(matsize2, cv::Formatter::FMT_PYTHON)
            << std::endl
            << "step(The first row bytes): " << matsize2.step << std::endl
            << "step[0](The first row bytes): " << matsize2.step[0] << std::endl
            << "step[1](The first element bytes): " << matsize2.step[1]
            << std::endl
            << "step1(0)(The first row element channel count): "
            << matsize2.step1(0) << std::endl
            << "step1(1)(The element channel count): " << matsize2.step1(1)
            << std::endl
            << std::endl;

  char arr2[] = {1, 2, 4};
  cv::Mat matsize3(size, CV_8UC3, arr2);
  std::cout << "mat3 = " << std::endl
            << " " << cv::format(matsize3, cv::Formatter::FMT_PYTHON)
            << std::endl
            << "step(The first row bytes): " << matsize3.step << std::endl
            << "step[0](The first row bytes): " << matsize3.step[0] << std::endl
            << "step[1](The first element bytes): " << matsize3.step[1]
            << std::endl
            << "step1(0)(The first row element channel count): "
            << matsize3.step1(0) << std::endl
            << "step1(1)(The element channel count): " << matsize3.step1(1)
            << std::endl
            << std::endl;

  /*
  cv::Mat(int ndims, const int* sizes, int type);
  cv::Mat(int ndims, const int* sizes, int type, const cv::Scalar& s);
  cv::Mat(int ndims, const int* sizes, int type, void* data, size_t step =
  AUTO_STEP);
  */

  // INFO:
  // https://stackoverflow.com/questions/18882242/how-do-i-get-the-size-of-a-multi-dimensional-cvmat-mat-or-matnd/18883062#18883062
  int size1[] = {3, 3, 3};
  cv::Mat matdims1(3, size1, CV_8UC3);

  cv::Mat matdims2(3, size1, CV_8UC3, cv::Scalar::all(255));
  std::cout << "matdims2.dims = " << matdims2.dims << " matdims2.size = [";
  for (int i = 0; i < matdims2.dims; ++i) {
    if (i)
      std::cout << " X ";
    std::cout << matdims2.size[i];
  }
  std::cout << "] matdims2.channels = " << matdims2.channels() << std::endl;

  char arr3[] = {1, 2, 4};
  cv::Mat matdims3(3, size1, CV_8UC3, arr3);
  std::cout << "matdims3.dims = " << matdims3.dims << " matdims3.size = [";
  for (int i = 0; i < matdims3.dims; ++i) {
    if (i)
      std::cout << " X ";
    std::cout << matdims3.size[i];
  }
  std::cout << "] matdims3.channels = " << matdims3.channels() << std::endl;

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
  std::cout << cv::format(m1, cv::Formatter::FMT_PYTHON) << std::endl;
  printf("Element (3,3) is (%f, %f)\n", m1.at<cv::Vec2f>(3, 3)[0],
         m1.at<cv::Vec2f>(3, 3)[1]);

  return 0;
}
