//
// Created by Zhou Wei Ran on 24/06/2017.
//

#ifndef IMAGEFILTERSANDDFT_GAUSSIAN1D_ZEROMEAN_H
#define IMAGEFILTERSANDDFT_GAUSSIAN1D_ZEROMEAN_H


class Gaussian1D_ZeroMean {
public:
    Gaussian1D_ZeroMean(double sigma);
    double  probabilityDensity_At(double x);

public:
    double getSigma() const;
    void setSigma(double sigma);

private:
    double sigma;
    double sigmaSquare_multiply_2;
    double constProductTerm;
};


#endif //IMAGEFILTERSANDDFT_GAUSSIAN1D_ZEROMEAN_H
