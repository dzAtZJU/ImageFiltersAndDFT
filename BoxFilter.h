//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_BOXFILTER_H
#define IMAGEFILTERSANDDFT_BOXFILTER_H

#include <cv.h>
using namespace cv;

class BoxFilter {
public:
    static void filter(Mat& image, Mat &filteredImage, int convokernel_widthHalf, int convokernel_heightHalf);
};


#endif //IMAGEFILTERSANDDFT_BOXFILTER_H
