#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <fstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::VideoCapture g_cap;

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;

void onTrackbarSlide(int pos, void *) {
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if (!g_dontset)
    g_run = 1;
  g_dontset = 0;
}

int main(int argc, char **argv) {
  cv::namedWindow("PlayWithTinker");
  g_cap.open("../Data/videos/vtest.avi");

  int frames = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_COUNT));
  int tmpw = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_WIDTH));
  int tmph = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_HEIGHT));

  std::cout << "Video has " << frames << " frames of dimensions(" << tmpw
            << ", " << tmph << ")." << std::endl;

  cv::createTrackbar("Position", "PlayWithTinker", &g_slider_position, frames,
                     onTrackbarSlide);
  cv::Mat frame;
  for (;;) {
    if (g_run != 0) {
      g_cap >> frame;
      if (frame.empty())
        break;

      int current_pos = static_cast<int>(g_cap.get(cv::CAP_PROP_POS_FRAMES));
      g_dontset = 1;

      cv::setTrackbarPos("Position", "PlayWithTinker", current_pos);
      cv::imshow("PlayWithTinker", frame);

      g_run -= 1;
    }

    char c = static_cast<char>(cv::waitKey(10));
    if (c == 's') {
      g_run = 1;
      std::cout << "Single step, run = " << g_run << std::endl;
    }
    if (c == 'r') {
      g_run = -1;
      std::cout << "Run mode, run = " << g_run << std::endl;
    }
    if (c == 27)
      break;
  }

  return 0;
}
