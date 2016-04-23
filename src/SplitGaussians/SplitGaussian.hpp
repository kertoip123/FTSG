#ifndef SRC_SPLIT_GAUSSIANS_HPP_
#define SRC_SPLIT_GAUSSIANS_HPP_

#include <opencv2/core/core.hpp>
using namespace cv;

#include "../SplitGaussians/Pixel.hpp"
#include "../Tools/tools.hpp"

class SplitGaussian
{
    private:
        Pixel **pixels = NULL;
        int height = 0;
        int width = 0;
        bool initFlag = false;

    public:
        SplitGaussian(double bgAlpha, double fgAlpha, double tb, double tf, double tl);
        ~SplitGaussian();

        bool isInitialized() { return initFlag; }

        void setFrameSize(int width, int height);
        void backgroundInit(int row, int col, uchar * rgb);
        void foregroundInit(int row, int col, uchar * rgb);

        void detection(const Mat & input, Mat & background, Mat & foreground);
        void update(int x, int y, bool updateFlag, double * rgb);

        void initialize(const Mat & input);

};

#endif /* SRC_SPLIT_GAUSSIANS_HPP_ */
