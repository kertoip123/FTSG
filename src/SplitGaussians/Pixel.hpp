#ifndef SRC_PIXEL_HPP_
#define SRC_PIXEL_HPP_

#include <vector>

#include "../Tools/tools.hpp"
#include "../SplitGaussians/BackgroundGaussian.hpp"
#include "../SplitGaussians/ForegroundGaussian.hpp"

using namespace std;

class Pixel
{
    private:
		ForegroundGaussian fgGaussian;
		vector <BackgroundGaussian> bgGaussians;

    public:

        void initialiseBackground(double weight, double * means, double std_dev);
        void initialiseForeground(double * means);

        bool isForeground(double * rgb);
        bool isBackground(double * rgb);

        void update(bool updateMask, double * rgb);

};

#endif /* SRC_PIXEL_HPP_ */
