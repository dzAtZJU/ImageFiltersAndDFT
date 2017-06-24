//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include <cmath>
#include "Gaussian1D_ZeroMean.h"

Gaussian1D_ZeroMean::Gaussian1D_ZeroMean(double sigma) :
        sigma(sigma), sigmaSquare_multiply_2(2*sigma*sigma), constProductTerm(1/sqrt(2*M_PI)/sigma){}

double Gaussian1D_ZeroMean::getSigma() const {
    return sigma;
}

void Gaussian1D_ZeroMean::setSigma(double sigma) {
    Gaussian1D_ZeroMean::sigma = sigma;
    Gaussian1D_ZeroMean::sigmaSquare_multiply_2 = 2*sigma*sigma;
    Gaussian1D_ZeroMean::constProductTerm = 1/sqrt(2*M_PI)/sigma;
}

double Gaussian1D_ZeroMean::probabilityDensity_At(double x) {
    auto probabilityDensity = constProductTerm*exp(-(x*x)/sigmaSquare_multiply_2);
    return probabilityDensity;
}
