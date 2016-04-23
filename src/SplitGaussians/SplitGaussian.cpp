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

void SplitGaussian::detection(const Mat & input, Mat & background, Mat & foreground, bool * isLargeChange){

	static Mat prevBackground;

	double input_rgb[RGB_COMPONENTS_NUM];

	const uchar * input_pixel_ptr;
	uchar * background_pixel_ptr;
	uchar * foreground_pixel_ptr;
	uchar * prev_bg_pixel_ptr;

	uchar bg_pixel, fg_pixel;
	double prev_bg_pixel, total_diff = 0;

	for(int row = 0; row < input.rows; ++row)
	{
		input_pixel_ptr = input.ptr(row);
		background_pixel_ptr = background.ptr(row);
		foreground_pixel_ptr = foreground.ptr(row);

		if(!prevBackground.empty())
			prev_bg_pixel_ptr = prevBackground.ptr(row);

	    for(int col = 0; col < input.cols; ++col)
	    {
	    	input_rgb[2] = (double)*input_pixel_ptr++;
	    	input_rgb[1] = (double)*input_pixel_ptr++;
	    	input_rgb[0] = (double)*input_pixel_ptr++;

	    	bg_pixel = (pixels[row][col].isBackground(input_rgb)) ? BLACK : WHITE;
	    	fg_pixel = (pixels[row][col].isForeground(input_rgb)) ? WHITE : BLACK;

	    	*background_pixel_ptr++ = bg_pixel;
	    	*foreground_pixel_ptr++ = fg_pixel;

	    	if(!prevBackground.empty()){
	    		prev_bg_pixel = (double)*prev_bg_pixel_ptr++;
	    		double diff = (double)bg_pixel - prev_bg_pixel;
	    		diff = (diff < 0) ? (-1*diff) : diff;
	    		total_diff += diff;
	    	}
	    }
	}


	total_diff = total_diff/(input.rows*input.cols);
	*isLargeChange = total_diff > 20;
	//cout << total_diff << endl;

	prevBackground = background.clone();
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
	    	pixels[row][col].insertBackgroundGaussian(0.2, input_rgb, 15);

	    }
	}

	numOfBgGaussians++;
	if(numOfBgGaussians == 5)
		initFlag = true;

}

void SplitGaussian::addNewGaussian(int x, int y, double weight, double * means, double sd){
	pixels[x][y].insertBackgroundGaussian(weight, means, sd);
}

