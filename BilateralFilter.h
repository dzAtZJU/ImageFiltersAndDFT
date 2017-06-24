//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_BILATERALFILTER_H
#define IMAGEFILTERSANDDFT_BILATERALFILTER_H

#include <cv.h>
#include "Gaussian2D_ZeroMeanDiagonalCov.h"
using namespace cv;

class BilateralFilter {
public:
    static void filter(Mat& image, Mat &filteredImage, double sigmas, double sigmar);
    static void constructGaussSKernel(const Gaussian2D_ZeroMeanDiagonalCov& gauss, int sideHalf, Mat& kernel);
};


#endif //IMAGEFILTERSANDDFT_BILATERALFILTER_H
