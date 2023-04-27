#include "opencv2/highgui.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char ** argv) {
  cv::namedWindow("VideoCapture");
  cv::VideoCapture cap;
  //cap.open(std::string(argv[1]));
  cap.open(0);

  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty()) {
      break;
    }
    cv::imshow("VideoCapture", frame);
    if (cv::waitKey(33) >= 0)
      break;
  }

  cv::destroyWindow("VideoCapture");

  return 0;
}
