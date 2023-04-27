#include "opencv2/core/matx.hpp"
#include "opencv2/core/utility.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

enum class ACCESS_TYPE { POINTER, ITERATOR, DYNMATIC };

void colorReduce_by_pointer(cv::Mat &inputImage, cv::Mat &outputImage, int div);
void colorReduce_by_iterator(cv::Mat &inputImage, cv::Mat &outputImage,
                             int div);
void colorReduce_by_dynamic(cv::Mat &inputImage, cv::Mat &outputImage, int div);

int main() {
  cv::Mat srcImage = cv::imread("../Data/lena.jpg");
  cv::imshow("Orignal", srcImage);

  //
  cv::Mat dstImage;
  dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
  {
    double start = static_cast<double>(cv::getTickCount());
    colorReduce_by_pointer(srcImage, dstImage, 32);
    auto duration = static_cast<double>(cv::getTickCount() - start) /
                    cv::getTickFrequency();
    std::cout << "Pointer Spend time: " << duration << std::endl;
  }
  {
    double start = static_cast<double>(cv::getTickCount());
    colorReduce_by_pointer(srcImage, dstImage, 32);
    auto duration = static_cast<double>(cv::getTickCount() - start) /
                    cv::getTickFrequency();
    std::cout << "Iterator Spend time: " << duration << std::endl;
  }
  {
    double start = static_cast<double>(cv::getTickCount());
    colorReduce_by_pointer(srcImage, dstImage, 32);
    auto duration = static_cast<double>(cv::getTickCount() - start) /
                    cv::getTickFrequency();
    std::cout << "dynamic address calc Spend time: " << duration << std::endl;
  }

  cv::imshow("Result", dstImage);
  cv::waitKey(0);

  return 0;
}

void colorReduce_by_pointer(cv::Mat &inputImage, cv::Mat &outputImage,
                            int div) {
  outputImage = inputImage.clone();
  int rowNumber = outputImage.rows;
  int colNumber = outputImage.cols * outputImage.channels();

  for (int i = 0; i < rowNumber; i++) {
    uchar *data = outputImage.ptr<uchar>(i);
    for (int j = 0; j < colNumber; j++) {
      data[j] = data[j] / div * div + div / 2;
    }
  }
}

void colorReduce_by_iterator(cv::Mat &inputImage, cv::Mat &outputImage,
                             int div) {
  outputImage = inputImage.clone();

  cv::Mat_<cv::Vec3b>::iterator it = outputImage.begin<cv::Vec3b>();
  cv::Mat_<cv::Vec3b>::iterator itend = outputImage.end<cv::Vec3b>();

  for (; it != itend; ++it) {
    (*it)[0] = (*it)[0] / div * div + div / 2;
    (*it)[1] = (*it)[1] / div * div + div / 2;
    (*it)[2] = (*it)[2] / div * div + div / 2;
  }
}

void colorReduce_by_dynamic(cv::Mat &inputImage, cv::Mat &outputImage,
                            int div) {
  outputImage = inputImage.clone();
  int rowNumber = outputImage.rows;
  int colNumber = outputImage.cols;

  for (int i = 0; i < rowNumber; i++) {
    for (int j = 0; j < colNumber; j++) {
      outputImage.at<cv::Vec3b>(i, j)[0] =
          outputImage.at<cv::Vec3b>(i, j)[0] / div * div + div / 2;
      outputImage.at<cv::Vec3b>(i, j)[1] =
          outputImage.at<cv::Vec3b>(i, j)[1] / div * div + div / 2;
      outputImage.at<cv::Vec3b>(i, j)[2] =
          outputImage.at<cv::Vec3b>(i, j)[2] / div * div + div / 2;
    }
  }
}
