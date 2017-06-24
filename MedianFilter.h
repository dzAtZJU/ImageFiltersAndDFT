//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_MEDIANFILTER_H
#define IMAGEFILTERSANDDFT_MEDIANFILTER_H

#include <cv.h>
using namespace cv;

class MedianFilter {
public:
    static void filter(Mat &image, Mat &filteredImage, int boxWidthHalf, int boxHeightHalf);

};


#endif //IMAGEFILTERSANDDFT_MEDIANFILTER_H
