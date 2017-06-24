//
// Created by Zhou Wei Ran on 13/06/2017.
//

#include "MyUtilityOpenCV.h"

std::vector<cv::Point2i> getNeighbors_incluSelf(Point2i pixel, int neighborHeight_Half, int neighborWidth_Half,
                                                int rows, int cols) {
    std::vector<Point2i> ns;
    for (int i = -neighborHeight_Half; i <= neighborHeight_Half; ++i) {
        for (int j = -neighborWidth_Half; j <= neighborWidth_Half; ++j) {
            auto neighbor = Point2i(pixel.x + j, pixel.y + i);
            auto row = neighbor.y, col = neighbor.x;
            if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols)) {
                    ns.push_back(neighbor);
            }
        }
    }
    return ns;
}

std::vector<char> fetchIntensities_ForCV_8UC1(const std::vector<Point2i> &coods, const Mat &channel) {
    std::vector<char> intensities;
    for(auto cood:coods) {
        auto intensity = channel.at<char>(cood);
        intensities.push_back(intensity);
    }
    return intensities;
}

double distanceInColorSpace_CV_8UC3(Point2i p, Point2i q, const Mat& image) {
    auto color_p = image.at<Vec3b>(p);
    auto color_q = image.at<Vec3b>(q);
    auto diff = color_p - color_q;
    auto d2 = (double)diff.dot(diff);
    return sqrt(d2);
}