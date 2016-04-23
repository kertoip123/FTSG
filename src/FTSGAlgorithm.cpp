/*
 * FTSGmethod.cpp
 *
 *  Created on: 21 lis 2015
 *      Author: Piotr Janus
 */

#include "FTSGAlgorithm.hpp"

FTSGAlgorithm::FTSGAlgorithm() {
	splitGaussian = NULL;
	fluxTensor = NULL;
}

FTSGAlgorithm::~FTSGAlgorithm() {
	delete splitGaussian;
	delete fluxTensor;
}

void FTSGAlgorithm :: update(const Mat & input, Mat & result, Mat & background, Mat & foreground, Mat & flux){

	if(result.empty()){
		int height = input.rows;
		int width = input.cols;
		splitGaussian->setFrameSize(width, height);

		updateMask = new bool* [height];
		for(int i=0; i<height; ++i)
			updateMask[i] = new bool [width];

		result = Mat(input.size(), CV_8U);
		background = Mat(input.size(), CV_8U);
		foreground = Mat(input.size(), CV_8U);
		flux = Mat(input.size(), CV_8U);
	}

	result.setTo(Scalar(BLACK,BLACK,BLACK));
	background.setTo(Scalar(BLACK,BLACK,BLACK));
	foreground.setTo(Scalar(BLACK,BLACK,BLACK));
	flux.setTo(Scalar(BLACK,BLACK,BLACK));

	if(!splitGaussian->isInitialized()){
		splitGaussian->initialize(input);
		return;
	}

	bool largeChange;
	fluxTensor->update(input, flux);
	splitGaussian->detection(input, background, foreground, &largeChange);

	Mat staticForeground = Mat(input.size(), CV_8U);
	Mat fusionResult = Mat(input.size(), CV_8U);

	fusion(flux, background, foreground, fusionResult, staticForeground);

	// revealed bg detection
	Mat revealed = Mat(input.size(), CV_8U);

	gaussianUpdate(input, revealed, largeChange);

	//temp
	result = fusionResult.clone();
	//result = staticForeground.clone();

}

void FTSGAlgorithm :: fusion(const Mat & flux, const Mat & background, const Mat & foreground, Mat & fusion, Mat & staticFg)
{
	const uchar * bg_pixel_ptr;
	const uchar * fg_pixel_ptr;
	const uchar * flux_pixel_ptr;
	uchar * fusion_pixel_ptr;
	uchar * static_pixel_ptr;

	uchar flux_pixel, bg_pixel, fg_pixel, fusion_pixel, static_pixel;

	bool bg, fg, ff, amb, fs;

	for(int row = 0; row < fusion.rows; ++row)
	{
		bg_pixel_ptr = background.ptr(row);
	    fg_pixel_ptr = foreground.ptr(row);
	    flux_pixel_ptr = flux.ptr(row);

	    fusion_pixel_ptr = fusion.ptr(row);
	    static_pixel_ptr = staticFg.ptr(row);

	    for(int col = 0; col < fusion.cols; ++col)
	    {
	       flux_pixel = *flux_pixel_ptr++;
	       bg_pixel = *bg_pixel_ptr++;
	       fg_pixel = *fg_pixel_ptr++;

	       bg = (bg_pixel == WHITE);
	       fg = (fg_pixel == WHITE);
	       ff = (flux_pixel == WHITE);

	       amb = (!ff && bg);
	       fs = (amb && fg);

	       updateMask[row][col] = (!bg || (amb && !fs));

	       if((ff && bg) || fs)
	    	   *fusion_pixel_ptr++ = WHITE;
	       else
	    	   *fusion_pixel_ptr++ = BLACK;

	       if(fs)
	    	   *static_pixel_ptr++ = WHITE;
	       else
	    	   *static_pixel_ptr++ = BLACK;

	    }
	}
}

void FTSGAlgorithm :: gaussianUpdate(const Mat & input, const Mat & revealed, bool largeChange){

	double input_rgb[RGB_COMPONENTS_NUM];

	const uchar * input_pixel_ptr;
	const uchar * revealed_pixel_ptr;

	uchar revealed_pixel;

	for(int row = 0; row < input.rows; ++row)
	{
		input_pixel_ptr = input.ptr(row);
		revealed_pixel_ptr = revealed.ptr(row);

	    for(int col = 0; col < input.cols; ++col)
	    {
	    	revealed_pixel = *revealed_pixel_ptr++;

	    	input_rgb[2] = (double)*input_pixel_ptr++;
	    	input_rgb[1] = (double)*input_pixel_ptr++;
	    	input_rgb[0] = (double)*input_pixel_ptr++;

	    	splitGaussian->update(row, col, updateMask[row][col], input_rgb);

	    	if(largeChange)
	    		splitGaussian->addNewGaussian(row, col, 0.2, input_rgb, 15);
	    	//insert/delete gaussians

	    }
	}
}

