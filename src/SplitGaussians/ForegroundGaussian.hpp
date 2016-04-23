/*
 * single_gaussian.h
 *
 *  Created on: 21 lis 2015
 *      Author: Piotr Janus
 */

#ifndef SRC_FOREGROUND_GAUSSIAN_HPP_
#define SRC_FOREGROUND_GAUSSIAN_HPP_

#include <math.h>
#include <cstring>

#include "../Tools/tools.hpp"

class ForegroundGaussian {

private:
	static double ALPHA;
	static double T_F;

    double mean [RGB_COMPONENTS_NUM];
    bool initFlag = false;

public:
    void initialise(double *gaussianMean);
    void getMean(double * gaussianMean);

    void update(double *rgb);
    bool checkPixelMatch(double *rgb);

    static void setAlpha(double alpha) {ForegroundGaussian::ALPHA = alpha; }
    static void setTF(double th) {ForegroundGaussian::T_F = th; }
};

#endif /* SRC_FOREGROUND_GAUSSIAN_HPP_ */
