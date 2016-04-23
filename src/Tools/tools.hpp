#ifndef SRC_TOOLS_HPP_
#define SRC_TOOLS_HPP_

const int RGB_COMPONENTS_NUM = 3;

double malahidanDistance(double * vectorX, double * vectorY, int size);
double count_probability_density(double * sample, double * mean, double standard_deviation);

typedef struct RGB{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}RGB;

const unsigned char BLACK = (unsigned char) 0;
const unsigned char WHITE = (unsigned char) 255;

#endif /* SRC_TOOLS_HPP_ */
