#include "opencv2/core/types.hpp"
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  // NOTE: The basic data types are those that are  assembled directly from C++
  // primitives. These types include simple vectors and matrices, as well as
  // representations of simple geometric concepts like points, rectangles,,
  // sizes, and the like.

  cv::Vec2b v2b;       // cv::Vec<>
  cv::Matx33f m33f;    // cv::Matx
  cv::Point2i p(0, 1); // cv::Point
  cv::Scalar s;        // cv::Scalar
  cv::Size sz;         // cv::Size
  cv::Rect r;          // cv::Rect
  cv::RotatedRect rr;  // cv::RotatedRect
  cv::Complexf z1;     // cv::Complexf

  // NOTE: These objects represent more abstract concepts such as the
  // garbage-collecting pointer class, range objects used for slicing, and
  // abstractions such as termination criteria.

  cv::TermCriteria tc;
  cv::Range rng;
  cv::Ptr<cv::Matx33f> ptr(new cv::Matx33f);
  cv::Exception e;
  cv::DataType<int> i;
  // cv::InputOutputArray ioarr;

  return 0;
}
