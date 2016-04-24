#ifndef _TESTS_HPP_
#define _TESTS_HPP_

#include <string>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

#define TEST_GROUP      1

#define COEF_LOG_ON      1
#define COEF_LOG_OFF     0
#define COUT if (COEF_LOG_ON) cout

// baseline
#if TEST_GROUP == 0

const int frame_num = 1700;
const int start_frame = 470;
const string input_frame_prefix = "tests/baseline/highway/input/in";
const string gt_frame_prefix = "tests/baseline/highway/groundtruth/gt";

#elif TEST_GROUP ==  1

const int frame_num = 2050;
const int start_frame = 570;
const string input_frame_prefix = "tests/baseline/office/input/in";
const string gt_frame_prefix = "tests/baseline/office/groundtruth/gt";

#elif TEST_GROUP ==  2

const int frame_num = 1099;
const int start_frame = 300;
const string input_frame_prefix = "tests/baseline/pedestrians/input/in";
const string gt_frame_prefix = "tests/baseline/pedestrians/groundtruth/gt";

#elif TEST_GROUP ==  3

const int frame_num = 1200;
const int start_frame = 300;
const string input_frame_prefix = "tests/baseline/PETS2006/input/in";
const string gt_frame_prefix = "tests/baseline/PETS2006/groundtruth/gt";

// intermittentObjectMotion
#elif TEST_GROUP ==  4

const int frame_num = 4500;
const int start_frame = 2450;
const string input_frame_prefix = "tests/intermittentObjectMotion/abandonedBox/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/abandonedBox/groundtruth/gt";

#elif TEST_GROUP ==  5

const int frame_num = 2500;
const int start_frame = 1100;
const string input_frame_prefix = "tests/intermittentObjectMotion/parking/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/parking/groundtruth/gt";

#elif TEST_GROUP ==  6

const int frame_num = 2750;
const int start_frame = 500;
const string input_frame_prefix = "tests/intermittentObjectMotion/sofa/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/sofa/groundtruth/gt";

#elif TEST_GROUP ==  7

const int frame_num = 3200;
const int start_frame = 175;
const string input_frame_prefix = "tests/intermittentObjectMotion/streetLight/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/streetLight/groundtruth/gt";

#elif TEST_GROUP ==  8

const int frame_num = 3200;
const int start_frame = 1320;
const string input_frame_prefix = "tests/intermittentObjectMotion/tramstop/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/tramstop/groundtruth/gt";

#elif TEST_GROUP ==  9

const int frame_num = 2500;
const int start_frame = 1000;
const string input_frame_prefix = "tests/intermittentObjectMotion/winterDriveway/input/in";
const string gt_frame_prefix = "tests/intermittentObjectMotion/winterDriveway/groundtruth/gt";

//shadow
#elif TEST_GROUP ==  10

const int frame_num = 2000;
const int start_frame = 400;
const string input_frame_prefix = "tests/shadow/backdoor/input/in";
const string gt_frame_prefix = "tests/shadow/backdoor/groundtruth/gt";

#elif TEST_GROUP ==  11

const int frame_num = 1700;
const int start_frame = 300;
const string input_frame_prefix = "tests/shadow/bungalows/input/in";
const string gt_frame_prefix = "tests/shadow/bungalows/groundtruth/gt";

#elif TEST_GROUP ==  12

const int frame_num = 1250;
const int start_frame = 300;
const string input_frame_prefix = "tests/shadow/busStation/input/in";
const string gt_frame_prefix = "tests/shadow/busStation/groundtruth/gt";

#elif TEST_GROUP ==  13

const int frame_num = 3400;
const int start_frame = 500;
const string input_frame_prefix = "tests/shadow/copyMachine/input/in";
const string gt_frame_prefix = "tests/shadow/copyMachine/groundtruth/gt";

#elif TEST_GROUP ==  14

const int frame_num = 7400;
const int start_frame = 1100;
const string input_frame_prefix = "tests/shadow/cubicle/input/in";
const string gt_frame_prefix = "tests/shadow/cubicle/groundtruth/gt";

#elif TEST_GROUP ==  15

const int frame_num = 1199;
const int start_frame = 250;
const string input_frame_prefix = "tests/shadow/peopleInShade/input/in";
const string gt_frame_prefix = "tests/shadow/peopleInShade/groundtruth/gt";

// thermal
#elif TEST_GROUP ==  16

const int frame_num = 5400;
const int start_frame = 500;
const string input_frame_prefix = "tests/thermal/corridor/input/in";
const string gt_frame_prefix = "tests/thermal/corridor/groundtruth/gt";

#elif TEST_GROUP ==  17

const int frame_num = 3700;
const int start_frame = 700;
const string input_frame_prefix = "tests/thermal/diningRoom/input/in";
const string gt_frame_prefix = "tests/thermal/diningRoom/groundtruth/gt";

#elif TEST_GROUP ==  18

const int frame_num = 6500;
const int start_frame = 1000;
const string input_frame_prefix = "tests/thermal/lakeSide/input/in";
const string gt_frame_prefix = "tests/thermal/lakeSide/groundtruth/gt";

#elif TEST_GROUP ==  19

const int frame_num = 4900;
const int start_frame = 600;
const string input_frame_prefix = "tests/thermal/library/input/in";
const string gt_frame_prefix = "tests/thermal/library/groundtruth/gt";

#elif TEST_GROUP ==  20

const int frame_num = 600;
const int start_frame = 250;
const string input_frame_prefix = "tests/thermal/park/input/in";
const string gt_frame_prefix = "tests/thermal/park/groundtruth/gt";


// dynamic background
#elif TEST_GROUP ==  21

const int frame_num = 7999;
const int start_frame = 1900;
const string input_frame_prefix = "tests/dynamicBackground/boats/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/boats/groundtruth/gt";

#elif TEST_GROUP ==  22

const int frame_num = 1189;
const int start_frame = 800;
const string input_frame_prefix = "tests/dynamicBackground/canoe/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/canoe/groundtruth/gt";

#elif TEST_GROUP ==  23

const int frame_num = 4000;
const int start_frame = 1000;
const string input_frame_prefix = "tests/dynamicBackground/fall/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/fall/groundtruth/gt";

#elif TEST_GROUP ==  24

const int frame_num = 1184;
const int start_frame = 400;
const string input_frame_prefix = "tests/dynamicBackground/fountain01/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/fountain01/groundtruth/gt";

#elif TEST_GROUP ==  25

const int frame_num = 1499;
const int start_frame = 500;
const string input_frame_prefix = "tests/dynamicBackground/fountain02/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/fountain02/groundtruth/gt";

#elif TEST_GROUP ==  26

const int frame_num = 3000;
const int start_frame = 1000;
const string input_frame_prefix = "tests/dynamicBackground/overpass/input/in";
const string gt_frame_prefix = "tests/dynamicBackground/overpass/groundtruth/gt";

// camera jitter
#elif TEST_GROUP ==  27

const int frame_num = 1150;
const int start_frame = 800;
const string input_frame_prefix = "tests/cameraJitter/badminton/input/in";
const string gt_frame_prefix = "tests/cameraJitter/badminton/groundtruth/gt";

#elif TEST_GROUP ==  28

const int frame_num = 2500;
const int start_frame = 790;
const string input_frame_prefix = "tests/cameraJitter/boulevard/input/in";
const string gt_frame_prefix = "tests/cameraJitter/boulevard/groundtruth/gt";

#elif TEST_GROUP ==  29

const int frame_num = 1200;
const int start_frame = 800;
const string input_frame_prefix = "tests/cameraJitter/sidewalk/input/in";
const string gt_frame_prefix = "tests/cameraJitter/sidewalk/groundtruth/gt";

#elif TEST_GROUP ==  30

const int frame_num = 1570;
const int start_frame = 900;
const string input_frame_prefix = "tests/cameraJitter/traffic/input/in";
const string gt_frame_prefix = "tests/cameraJitter/traffic/groundtruth/gt";

// turbulence
#elif TEST_GROUP ==  31

const int frame_num = 5000;
const int start_frame = 1000;
const string input_frame_prefix = "tests/turbulence/turbulence0/input/in";
const string gt_frame_prefix = "tests/turbulence/turbulence0/groundtruth/gt";

#elif TEST_GROUP ==  32

const int frame_num = 4000;
const int start_frame = 1200;
const string input_frame_prefix = "tests/turbulence/turbulence1/input/in";
const string gt_frame_prefix = "tests/turbulence/turbulence1/groundtruth/gt";

#elif TEST_GROUP ==  33

const int frame_num = 4500;
const int start_frame = 500;
const string input_frame_prefix = "tests/turbulence/turbulence2/input/in";
const string gt_frame_prefix = "tests/turbulence/turbulence2/groundtruth/gt";

#elif TEST_GROUP ==  34

const int frame_num = 2200;
const int start_frame = 800;
const string input_frame_prefix = "tests/turbulence/turbulence3/input/in";
const string gt_frame_prefix = "tests/turbulence/turbulence3/groundtruth/gt";

// PTZ

#elif TEST_GROUP ==  35

const int frame_num = 1700;
const int start_frame = 600;
const string input_frame_prefix = "tests/PTZ/continuousPan/input/in";
const string gt_frame_prefix = "tests/PTZ/continuousPan/groundtruth/gt";

#elif TEST_GROUP ==  36

const int frame_num = 3500;
const int start_frame = 1200;
const string input_frame_prefix = "tests/PTZ/intermittentPan/input/in";
const string gt_frame_prefix = "tests/PTZ/intermittentPan/groundtruth/gt";

#elif TEST_GROUP ==  37

const int frame_num = 2300;
const int start_frame = 800;
const string input_frame_prefix = "tests/PTZ/twoPositionPTZCam/input/in";
const string gt_frame_prefix = "tests/PTZ/twoPositionPTZCam/groundtruth/gt";

#elif TEST_GROUP ==  38

const int frame_num = 1130;
const int start_frame = 500;
const string input_frame_prefix = "tests/PTZ/zoomInZoomOut/input/in";
const string gt_frame_prefix = "tests/PTZ/zoomInZoomOut/groundtruth/gt";

// night videos
#elif TEST_GROUP ==  39

const int frame_num = 2500;
const int start_frame = 1000;
const string input_frame_prefix = "tests/nightVideos/bridgeEntry/input/in";
const string gt_frame_prefix = "tests/nightVideos/bridgeEntry/groundtruth/gt";

#elif TEST_GROUP ==  40

const int frame_num = 2760;
const int start_frame = 730;
const string input_frame_prefix = "tests/nightVideos/busyBoulvard/input/in";
const string gt_frame_prefix = "tests/nightVideos/busyBoulvard/groundtruth/gt";

#elif TEST_GROUP ==  41

const int frame_num = 1364;
const int start_frame = 400;
const string input_frame_prefix = "tests/nightVideos/fluidHighway/input/in";
const string gt_frame_prefix = "tests/nightVideos/fluidHighway/groundtruth/gt";

#elif TEST_GROUP ==  42

const int frame_num = 5200;
const int start_frame = 800;
const string input_frame_prefix = "tests/nightVideos/streetCornerAtNight/input/in";
const string gt_frame_prefix = "tests/nightVideos/streetCornerAtNight/groundtruth/gt";

#elif TEST_GROUP ==  43

const int frame_num = 3000;
const int start_frame = 500;
const string input_frame_prefix = "tests/nightVideos/tramStation/input/in";
const string gt_frame_prefix = "tests/nightVideos/tramStation/groundtruth/gt";

#elif TEST_GROUP ==  44

const int frame_num = 1785;
const int start_frame = 900;
const string input_frame_prefix = "tests/nightVideos/winterStreet/input/in";
const string gt_frame_prefix = "tests/nightVideos/winterStreet/groundtruth/gt";

#endif

void count_coefficients(Mat & result, Mat & gt_frame);
void print_metrics(void);

#endif
