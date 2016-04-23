#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../Tools/tools.hpp"
#include "../SplitGaussians/SplitGaussian.hpp"

SplitGaussian::SplitGaussian(double bgAlpha, double fgAlpha, double tb, double tf, double tl)
{
	ForegroundGaussian::setAlpha(fgAlpha);
	ForegroundGaussian::setTF(tf);

	BackgroundGaussian::setAlpha(bgAlpha);
	BackgroundGaussian::setTB(tb);
}

SplitGaussian::~SplitGaussian()
{
	for(int i=0; i < height; i++)
		delete [] pixels[i];
	delete [] pixels;

}

void SplitGaussian::setFrameSize(int width, int height){

	if(pixels != NULL){
		for(int i=0; i < height; i++)
			delete [] pixels[i];
		delete [] pixels;
	}

	this->width = width;
	this->height = height;

	pixels = new Pixel*[height];
    for(int i=0; i < height; ++i)
        pixels[i] = new Pixel[width];
}

void SplitGaussian::update(int x, int y, bool updateFlag, double * rgb){

	pixels[x][y].update(updateFlag, rgb);

}

void SplitGaussian::detection(const Mat & input, Mat & background, Mat & foreground){

	double input_rgb[RGB_COMPONENTS_NUM];

	const uchar * input_pixel_ptr;
	uchar * background_pixel_ptr;
	uchar * foreground_pixel_ptr;

	uchar bg_pixel, fg_pixel;

	for(int row = 0; row < input.rows; ++row)
	{
		input_pixel_ptr = input.ptr(row);
		background_pixel_ptr = background.ptr(row);
		foreground_pixel_ptr = foreground.ptr(row);

	    for(int col = 0; col < input.cols; ++col)
	    {
	    	input_rgb[2] = (double)*input_pixel_ptr++;
	    	input_rgb[1] = (double)*input_pixel_ptr++;
	    	input_rgb[0] = (double)*input_pixel_ptr++;

	    	bg_pixel = (pixels[row][col].isBackground(input_rgb)) ? BLACK : WHITE;
	    	fg_pixel = (pixels[row][col].isForeground(input_rgb)) ? WHITE : BLACK;

	    	*background_pixel_ptr++ = bg_pixel;
	    	*foreground_pixel_ptr++ = fg_pixel;
	    }
	}
}

void SplitGaussian::initialize(const Mat & input){

	static int numOfBgGaussians = 0;

	double input_rgb[RGB_COMPONENTS_NUM];
	const uchar * input_pixel_ptr;

	for(int row = 0; row < input.rows; ++row)
	{
		input_pixel_ptr = input.ptr(row);

	    for(int col = 0; col < input.cols; ++col)
	    {
	    	input_rgb[2] = (double)*input_pixel_ptr++;
	    	input_rgb[1] = (double)*input_pixel_ptr++;
	    	input_rgb[0] = (double)*input_pixel_ptr++;

	    	//pixels[row][col].initialiseForeground(input_rgb);
	    	pixels[row][col].initialiseBackground(0.2, input_rgb, 10);

	    }
	}


	numOfBgGaussians++;
	if(numOfBgGaussians == 5)
		initFlag = true;

}

