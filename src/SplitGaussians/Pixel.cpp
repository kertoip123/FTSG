#include <iostream>
#include <algorithm>

#include "../Tools/tools.hpp"
#include "../SplitGaussians/Pixel.hpp"

bool Pixel::isForeground(double * rgb){
	return fgGaussian.checkPixelMatch(rgb);
}

bool Pixel::isBackground(double * rgb){
	double sigma = 0;
	double sd, w;

	for(unsigned i=0; i<bgGaussians.size(); ++i){
		sd = bgGaussians[i].getStdDeviation();
		w = bgGaussians[i].getWeight();
		sigma += sd*w;
	}

	double dmin = 1, d;
	int minIndex = 0;
	for(unsigned i=0; i<bgGaussians.size(); ++i){
		bgGaussians[i].setMatchedFlag(false);
		d =  bgGaussians[i].checkPixelMatch(rgb, sigma);

		if(i==0) {
			dmin = d;
		}
		else{
			dmin = (dmin > d) ? d : dmin;
			minIndex = i;
		}
	}

	if(dmin > 0){
		return false;
	}
	else{
		bgGaussians[minIndex].setMatchedFlag(true);
		return true;
	}
}

void Pixel::update(bool updateMask, double * rgb){
	if(updateMask){
		for(unsigned i=0; i<bgGaussians.size(); ++i){
			if(bgGaussians[i].isMatched())
				bgGaussians[i].updateMatched(rgb);
			else
				bgGaussians[i].updateUnmatched();
		}
	}
	else{
		fgGaussian.update(rgb);
	}
}

void Pixel::initialiseBackground(double weight, double * means, double std_dev){
	BackgroundGaussian newGaussian;
	newGaussian.initialise(weight, means, std_dev);
	bgGaussians.push_back(newGaussian);
}

void Pixel::initialiseForeground(double * means){
	fgGaussian.initialise(means);
}
