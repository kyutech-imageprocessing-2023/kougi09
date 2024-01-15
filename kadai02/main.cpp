#include <iostream>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>


void display(cv::Mat image, std::string windowName = "Image") {
    cv::namedWindow(windowName);
    cv::imshow(windowName, image);
    cv::waitKey(1000 * 100);
    cv::destroyWindow(windowName);
}

int main(int argc, char* argv[]){

  cv::Mat img = cv::imread("objects.png", 0);
  cv::bitwise_not(img, img);  // 白の部分をラベル付けするので、白黒反転画像にする

  cv::Mat img_label;

  // connectedComponentsが領域のラベル付けをする
  // img_label の値（画素に対応するラベル）は、img_label.at<uint>(j, i) で取得できる
  // ラベルの値は、 0が背景、1,2,3 が各オブジェクト
  // n はラベルの数
  int n = cv::connectedComponents(img, img_label);

  int x_size = img.cols;
  int y_size = img.rows;
  int i, j;
  cv::Mat img_out = img.clone();
  for( i=0 ; i<x_size ; i++ ){
    for( j=0 ; j<y_size ; j++ ){
      // ここを作成する
    }
  }


  display(img_out);

  return 0;
}

