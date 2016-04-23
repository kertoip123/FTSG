/*
 * FTSGmethod.hpp
 *
 *  Created on: 21 lis 2015
 *      Author: Piotr Janus
 */
#ifndef SRC_FTSG_ALGORITHM_HPP_
#define SRC_FTSG_ALGORITHM_HPP_

#include <opencv2/core/core.hpp>
#include "SplitGaussians/SplitGaussian.hpp"
#include "FluxTensor/FluxTensorMethod.hpp"

using namespace cv;

class FTSGAlgorithm {
public:
	FTSGAlgorithm();
	~FTSGAlgorithm();

	void update(const Mat & input, Mat & result, Mat & background, Mat & foreground, Mat & flux);

	void setSplitGaussianParam(double bgAlpha, double fgAlpha, double tb, double tf, double tl){
		splitGaussian = new SplitGaussian(bgAlpha, fgAlpha, tb, tf, tl);
	}

	void setFluxTensorParam(double th, int nDs, int nDt, int nAs, int nAt){
		fluxTensor = new FluxTensorMethod(nDs, nDt, nAs, nAt, th);
	}

private:
	SplitGaussian * splitGaussian;
	FluxTensorMethod * fluxTensor;
	bool ** updateMask = NULL;

	void fusion(const Mat & flux, const Mat & background, const Mat & foreground, Mat & fusion, Mat & staticFg);

	void gaussianUpdate(const Mat & input, const Mat & revealed, bool largeChange);

};

#endif /* SRC_FTSG_ALGORITHM_HPP_ */
