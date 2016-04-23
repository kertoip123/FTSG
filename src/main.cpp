#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/opencv.hpp>

#include "FTSGAlgorithm.hpp"
#include "tools/file_name_generator.hpp"
#include "tools/window_manager.hpp"


using namespace cv;
using namespace std;

const string input_path = "tests/highway/input";
const int frame_num = 1700;


int main(int argc, char** argv)
{
    FTSGAlgorithm ftsg;
    ftsg.setFluxTensorParam(30,5,5,5,5);
    ftsg.setSplitGaussianParam(0.004, 0.5, 3, 20, 0.1);

	FileNameGenerator input_file_name_generator(input_path+"/in", JPG);
	//FileNameGenerator ground_truth_file_name_generator(gt_frame_prefix, PNG);

    initialize_windows();

    Mat input_frame, flux_output_frame, bg_frame, fg_frame, result_frame;

    string frame_name, gt_name;

    for(int frame_id = 1; frame_id < frame_num; frame_id++)
    {
        frame_name = input_file_name_generator.get_frame_name(frame_id);
       // gt_name = ground_truth_file_name_generator.get_frame_name(frame_id);

        input_frame = imread(frame_name, 1);

        //gt_frame = imread(gt_name, 0);

        ftsg.update(input_frame, result_frame, bg_frame, fg_frame, flux_output_frame);

        update_windows(4, &input_frame, &flux_output_frame, &bg_frame, &fg_frame);


        if(waitKey(1) != -1)
            break;
    }

    return 0;

}
