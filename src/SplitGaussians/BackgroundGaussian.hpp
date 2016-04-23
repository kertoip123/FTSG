#ifndef SRC_GAUSSIAN_HPP_
#define SRC_GAUSSIAN_HPP_

#include <opencv2/core/core.hpp>

#include "../Tools/tools.hpp"
using namespace cv;

class BackgroundGaussian
{
    private:
		static double INITIAL_VARIANCE;
		static double ALPHA;
		static double T_B;

		double weight;
        double mean [RGB_COMPONENTS_NUM];
        double stdDeviation; //same for all RGB values, sigma without square

        bool matchedFlag;

    public:
        void initialise(double weight, double *gaussianMean, double stdDeviation);

        void getMean(double * gaussianMeans);
        double getWeight() { return weight; }
        double getStdDeviation() { return stdDeviation; }

        void setMatchedFlag(bool flag) { matchedFlag = flag; }
        bool isMatched() { return matchedFlag; }

        void updateUnmatched();
        void updateMatched(double *rgb);

        double checkPixelMatch(double *rgb, double sigma);

        static double& getInitialVariance() { return BackgroundGaussian::INITIAL_VARIANCE; }
        static void setAlpha(double alpha) {BackgroundGaussian::ALPHA = alpha; }
        static void setTB(double th) {BackgroundGaussian::T_B = th; }

};


#endif /* SRC_GAUSSIAN_HPP_ */
