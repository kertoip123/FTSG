#include <math.h>

#include "../Tools/tools.hpp"

double malahidanDistance(double * vectorX, double * vectorY, int size)
{
    double sum = 0, temp;
    for(int i = 0; i < size; ++i)
    {
        temp = vectorX[i] - vectorY[i];
        sum += temp*temp;
    }
    return sum;
}

double count_probability_density(double * sample, double * mean, double standard_deviation)
{
    double std_dev_square = standard_deviation*standard_deviation;
    double std_dev_determinant = 1.0, pi_constant = 1;
    for(int i=0; i<3; ++i)
    {
        std_dev_determinant *= std_dev_square;
        pi_constant *= 2.0*(M_PI); //Assuming n means dimension (n=3)
    }
    std_dev_determinant = sqrt(std_dev_determinant);
    pi_constant = sqrt(pi_constant);

    double exponent_arg = malahidanDistance(sample, mean, 3)/std_dev_square;
    exponent_arg /= (-2.0);

    double res = exp(exponent_arg);
    res /= std_dev_determinant;
    res /= pi_constant;

    return res;
}
