//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include "BoxFilter.h"

void BoxFilter::filter(Mat &image, Mat &filteredImage, int convokernel_widthHalf, int convokernel_heightHalf){
    auto kernelH = 2*convokernel_heightHalf+1;
    auto kernelW = 2*convokernel_widthHalf+1;
    auto kernel = Mat(kernelH, kernelW, CV_64FC1, Scalar(1.0/(kernelH*kernelW)));
    filter2D(image, filteredImage, -1, kernel, Point(convokernel_widthHalf, convokernel_heightHalf));
}
