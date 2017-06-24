//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_GAUSSIAN2D_ZEROMEANDIAGONALCOV_H
#define IMAGEFILTERSANDDFT_GAUSSIAN2D_ZEROMEANDIAGONALCOV_H


class Gaussian2D_ZeroMeanDiagonalCov {
public:
    Gaussian2D_ZeroMeanDiagonalCov(double sigma);
    double  probabilityDensity_At(double u, double v) const;

public:
    double getSigma() const;
    void setSigma(double sigma);

private:
    double sigma;
    double sigmaSquare_multiply_2;
    double constProductTerm;
};


#endif //IMAGEFILTERSANDDFT_GAUSSIAN2D_ZEROMEANDIAGONALCOV_H
