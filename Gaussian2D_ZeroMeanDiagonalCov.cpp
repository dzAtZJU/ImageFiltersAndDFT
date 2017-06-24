//
// Created by Zhou Wei Ran on 24/06/2017.
//

#include <math.h>
#include "Gaussian2D_ZeroMeanDiagonalCov.h"

Gaussian2D_ZeroMeanDiagonalCov::Gaussian2D_ZeroMeanDiagonalCov(double sigma) :
        sigma(sigma), sigmaSquare_multiply_2(2*sigma*sigma), constProductTerm(1.0/M_PI/sigmaSquare_multiply_2){}

double Gaussian2D_ZeroMeanDiagonalCov::getSigma() const {
    return sigma;
}

void Gaussian2D_ZeroMeanDiagonalCov::setSigma(double sigma) {
    Gaussian2D_ZeroMeanDiagonalCov::sigma = sigma;
    Gaussian2D_ZeroMeanDiagonalCov::sigmaSquare_multiply_2 = 2*sigma*sigma;
    Gaussian2D_ZeroMeanDiagonalCov::constProductTerm = 1.0/M_PI/sigmaSquare_multiply_2;
}

double Gaussian2D_ZeroMeanDiagonalCov::probabilityDensity_At(double u, double v) const {
    auto probabilityDensity = constProductTerm*exp(-(u*u+v*v)/sigmaSquare_multiply_2);
    return probabilityDensity;
}
