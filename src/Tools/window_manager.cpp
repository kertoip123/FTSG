#include <opencv2/highgui/highgui.hpp>
#include "window_manager.hpp"

void initialize_windows()
{
	namedWindow(INPUT, CV_WINDOW_AUTOSIZE);
	namedWindow(RESULT, CV_WINDOW_AUTOSIZE);
	namedWindow(BACKGROUND, CV_WINDOW_AUTOSIZE);
	namedWindow(FOREGROUND, CV_WINDOW_AUTOSIZE);

	moveWindow(INPUT, WINDOW_PADDING, WINDOW_PADDING);
	moveWindow(RESULT, WINDOW_PADDING + WINDOW_X_POS_OFFSET, WINDOW_PADDING);
	moveWindow(BACKGROUND, WINDOW_PADDING + 2*WINDOW_X_POS_OFFSET, WINDOW_PADDING);
	moveWindow(FOREGROUND, WINDOW_PADDING + 3*WINDOW_X_POS_OFFSET, WINDOW_PADDING);
}

void update_windows(int windows_num, ...)
{
    va_list args;
    va_start(args, windows_num);
    Mat *img;
    img = va_arg(args, Mat *);
	imshow(INPUT, *img);
 	img = va_arg(args, Mat *);
	imshow(RESULT, *img);
    img = va_arg(args, Mat *);
	imshow(BACKGROUND, *img);
	img = va_arg(args, Mat *);
	imshow(FOREGROUND, *img);

}
