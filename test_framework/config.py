from test import Test

#Compile settings

APP_NAME             = "FTSG.exe"
OPENCV_INCLUDES_DIR  = "test_framework/opencv/include"
OPENCV_LIBS_DIR      = "test_framework/opencv/libs"
COMPILE_DIR          = "Debug/"
SLASH                = "/"

LIBRARIES           = " -llibopencv_calib3d300 -llibopencv_core300 -llibopencv_features2d300 -llibopencv_flann300 -llibopencv_highgui300 -llibopencv_imgcodecs300 -llibopencv_imgproc300 -llibopencv_ml300 -llibopencv_objdetect300 -llibopencv_photo300 -llibopencv_shape300 -llibopencv_stitching300 -llibopencv_superres300 -llibopencv_video300 -llibopencv_videoio300 -llibopencv_videostab300"

src_files = ["SplitGaussians/BackgroundGaussian",
             "SplitGaussians/ForegroundGaussian",
             "SplitGaussians/Pixel",
             "SplitGaussians/SplitGaussian",
             "FluxTensor/FluxTensorMethod",
             "FTSGAlgorithm",
             "Tools/file_name_generator",
             "Tools/tests",
             "Tools/tools",
             "Tools/window_manager",
             "main"]

#Test settings
tests = {
            "baseline": [Test("highway", 0), Test("office", 1), Test("pedestrians", 2), Test("PETS2006", 3)]
            #Add more categories
        }

#Output settings
OUTPUT_FILE = "test_framework/results.txt"

if __name__ == "__main__":
    for cat in tests:
        test_seqs = tests[cat]
        for test_seq in test_seqs:
            print(test_seq)