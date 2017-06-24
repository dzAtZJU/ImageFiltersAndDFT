//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include "BilateralFilter.h"
#include "Gaussian2D_ZeroMeanDiagonalCov.h"
#include "Gaussian1D_ZeroMean.h"
#include "MyUtilityOpenCV.h"

void BilateralFilter::filter(Mat &image, Mat &filteredImage, double sigmas, double sigmar) {
    Gaussian2D_ZeroMeanDiagonalCov gaussS(sigmas);
    Gaussian1D_ZeroMean gaussR(sigmar);

    auto gaussS_sideHalf = int(5*sigmas);
    Mat gaussS_Kernel;
    constructGaussSKernel(gaussS, gaussS_sideHalf, gaussS_Kernel);

    for (int row = 0; row < image.rows; ++row) {
        std::cout<<"row "<<row<<std::endl;
        for (int col = 0; col < image.cols; ++col) {
            Vec3d I = {0.0, 0.0, 0.0};
            double normTerm = 0.0;
            auto neighbors_coods = getNeighbors_incluSelf(Point2i(col, row), gaussS_sideHalf, gaussS_sideHalf, image.rows, image.cols);
            for (auto n:neighbors_coods) {
                auto colorDiff = distanceInColorSpace_CV_8UC3(Point2i(col, row), n, image);
                auto rangeFactor = gaussR.probabilityDensity_At(colorDiff);
                auto spaceFactor = gaussS_Kernel.at<double>(n.y - row + gaussS_sideHalf, n.x - col + gaussS_sideHalf);
                auto I_n = (Vec3d)image.at<Vec3b>(n);
                normTerm += rangeFactor*spaceFactor;
                I += rangeFactor*spaceFactor*I_n;
            }
            I /= normTerm;
            auto color = (Vec3b)I;
            filteredImage.at<Vec3b>(row, col) = color;
        }
    }
}

void BilateralFilter::constructGaussSKernel(const Gaussian2D_ZeroMeanDiagonalCov &gauss, int sideHalf, Mat &kernel) {
    auto side = 2*sideHalf+1;
    kernel.create(side, side, CV_64FC1);
    for (int i = 0; i < kernel.rows; ++i) {
        for (int j = 0; j < kernel.cols; ++j) {
            kernel.at<double>(i, j) = gauss.probabilityDensity_At(i-sideHalf, j-sideHalf);
        }
    }
}
