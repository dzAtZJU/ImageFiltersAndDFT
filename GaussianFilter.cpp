//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include "GaussianFilter.h"
#include "Gaussian2D_ZeroMeanDiagonalCov.h"

void GaussianFilter::filter(Mat &image, Mat &filteredImage, double sigma) {
    auto gauss = Gaussian2D_ZeroMeanDiagonalCov(sigma);

    auto gausskernel_sideHalf = int(5*sigma);
    auto side = 2*gausskernel_sideHalf+1;
    auto kernel = Mat(side, side, CV_64FC1, Scalar(0));
    for (int i = 0; i < kernel.rows; ++i) {
        for (int j = 0; j < kernel.cols; ++j) {
            kernel.at<double>(i, j) = gauss.probabilityDensity_At(i-gausskernel_sideHalf, j-gausskernel_sideHalf);
        }
    }

    filter2D(image, filteredImage, -1, kernel, Point(gausskernel_sideHalf, gausskernel_sideHalf));
}
