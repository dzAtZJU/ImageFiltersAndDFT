//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include "MedianFilter.h"
#include "MyUtilityOpenCV.h"

void MedianFilter::filter(Mat &image, Mat &filteredImage, int boxWidthHalf, int boxHeightHalf) {

    std::vector<Mat> imageChannels;
    split(image, imageChannels);

    for (int row = 0; row < image.rows; ++row) {
        for (int col = 0; col < image.cols; ++col) {
            std::cout<<"row "<<row<<std::endl;
            auto neighbors_coods = getNeighbors_incluSelf(Point2i(col, row), boxHeightHalf, boxWidthHalf, image.rows,
                                                          image.cols);
            Vec3b color;
            for (int c = 0; c < image.channels(); ++c) {
                auto channel = imageChannels[c];
                auto neighbors_intensities = fetchIntensities_ForCV_8UC1(neighbors_coods, channel);
                std::sort(neighbors_intensities.begin(), neighbors_intensities.end());
                auto median = neighbors_intensities[neighbors_intensities.size()/2];
                color[c] = median;
            }
            filteredImage.at<Vec3b>(row,col) = color;
        }
    }
}