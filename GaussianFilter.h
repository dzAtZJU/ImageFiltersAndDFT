//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_GAUSSIANFILTER_H
#define IMAGEFILTERSANDDFT_GAUSSIANFILTER_H

#include <cv.h>
using namespace cv;

class GaussianFilter {
public:
    static void filter(Mat& image, Mat &filteredImage, double sigma);
};


#endif //IMAGEFILTERSANDDFT_GAUSSIANFILTER_H
