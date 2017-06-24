#include <highgui.h>
#include "BoxFilter.h"
#include "GaussianFilter.h"
#include "MedianFilter.h"
#include "BilateralFilter.h"
/*
//Box Filter
int main(int argc, char* argv[]) {
    auto imagePath = argv[1]; //"/Users/zhouweiran/Desktop/fox.png";
    auto destPath = argv[2]; //"/Users/zhouweiran/Desktop/foxfilt.png";
    auto convokernel_widthHalf = atoi(argv[3]);
    auto convokernel_heightHalf = atoi(argv[4]);

    auto image = imread(imagePath);
    auto filteredImage = Mat(image.size(), image.type());
    BoxFilter::filter(image, filteredImage, convokernel_widthHalf, convokernel_heightHalf);
    imwrite(destPath, filteredImage);
}
*/

/*
//Gaussian Filter
int main(int argc, char* argv[]) {
    auto imagePath = argv[1];
    auto destPath = argv[2];
    auto sigma = atof(argv[3]);

    auto image = imread(imagePath);
    auto filteredImage = Mat(image.size(), image.type());
    GaussianFilter::filter(image, filteredImage, sigma);
    imwrite(destPath, filteredImage);
}
*/

/*
//Median Filter
int main(int argc, char* argv[]) {
    auto imagePath = argv[1];
    auto destPath = argv[2];
    auto boxWidthHalf = atoi(argv[3]);
    auto boxHeightHalf = atoi(argv[4]);

    auto image = imread(imagePath);
    auto filteredImage = Mat(image.size(), image.type());

    MedianFilter::filter(image, filteredImage, boxWidthHalf, boxHeightHalf);
    imwrite(destPath, filteredImage);
}
*/

/*
//Bilateral Filter
int main(int argc, char* argv[]) {
    auto imagePath = argv[1];
    auto destPath = argv[2];
    auto sigmaS = atoi(argv[3]);
    auto sigmaR = atoi(argv[4]);

    auto image = imread(imagePath);
    auto filteredImage = Mat(image.size(), image.type());

    BilateralFilter::filter(image, filteredImage, sigmaS, sigmaR);
    imwrite(destPath, filteredImage);
}
*/

//FFT
void fftshift(const Mat &src, Mat &dst) {
    dst.create(src.size(), src.type());

    int rows = src.rows, cols = src.cols;
    Rect roiTopBand, roiBottomBand, roiLeftBand, roiRightBand;

    if (rows % 2 == 0) {
        roiTopBand    = Rect(0, 0, cols, rows / 2);
        roiBottomBand = Rect(0, rows / 2, cols, rows / 2);
    } else {
        roiTopBand    = Rect(0, 0, cols, rows / 2 + 1);
        roiBottomBand = Rect(0, rows / 2 + 1, cols, rows / 2);
    }

    if (cols % 2 == 0) {
        roiLeftBand   = Rect(0, 0, cols / 2, rows);
        roiRightBand  = Rect(cols / 2, 0, cols / 2, rows);
    } else {
        roiLeftBand   = Rect(0, 0, cols / 2 + 1, rows);
        roiRightBand  = Rect(cols / 2 + 1, 0, cols / 2, rows);
    }

    Mat srcTopBand    = src(roiTopBand);
    Mat dstTopBand    = dst(roiTopBand);
    Mat srcBottomBand = src(roiBottomBand);
    Mat dstBottomBand = dst(roiBottomBand);
    Mat srcLeftBand   = src(roiLeftBand);
    Mat dstLeftBand   = dst(roiLeftBand);
    Mat srcRightBand  = src(roiRightBand);
    Mat dstRightBand  = dst(roiRightBand);
    flip(srcTopBand, dstTopBand, 0);
    flip(srcBottomBand, dstBottomBand, 0);
    flip(dst, dst, 0);
    flip(srcLeftBand, dstLeftBand, 1);
    flip(srcRightBand, dstRightBand, 1);
    flip(dst, dst, 1);
}

int main(int argc, char* argv[]) {
    // rearranges the outputs of dft by moving the zero-frequency component to the center of the array.

    Mat I(512, 512, CV_32FC1);
    I(Rect(256-10, 256-30, 20, 60)) = 1.0;
    Mat J(I.size(), CV_32FC2);
    dft(I, J, DFT_COMPLEX_OUTPUT);
    fftshift(J, J);

    Mat Mag;
    std::vector<Mat> K;
    split(J, K);        // 将实数和虚数部分分解到 K[0] 和 K[1]
    pow(K[0], 2, K[0]); // 计算平方
    pow(K[1], 2, K[1]);
    Mag = K[0]+K[1];    // 两个分量的平方和

    Mat logMag;
    log(Mag+1, logMag);
    normalize(logMag, logMag, 1.0, 0.0, CV_MINMAX);
// ...
    imshow("Magnitude", logMag);
    waitKey(0);
}

