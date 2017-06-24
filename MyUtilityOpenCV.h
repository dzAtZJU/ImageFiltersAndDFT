//
// Created by Zhou Wei Ran on 13/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_MYUTILITYOPENCV_H
#define IMAGEFILTERSANDDFT_MYUTILITYOPENCV_H

#include <cv.h>
using namespace cv;

std::vector<cv::Point2i> getNeighbors_incluSelf(Point2i pixel, int neighborHeight_Half, int neighborWidth_Half,
                                                int rows, int cols);
std::vector<char> fetchIntensities_ForCV_8UC1(const std::vector<Point2i>& coods, const Mat& channel);

double distanceInColorSpace_CV_8UC3(Point2i p, Point2i q, const Mat& image);
#endif
