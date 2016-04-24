import subprocess
import os
import shutil

WORKING_PATH = str()
OPENCV_INCLUDES_DIR  = "test_framework\\opencv\\include"
OPENCV_LIBS_DIR      = "test_framework\\opencv\\libs"
COMPILE_DIR          = "Debug\\"
SLASH                = "\\"

APP_NAME            = "FTSG.exe"
COMPILE_COMMAND     = "g++ \"-I%s\" -O0 -g3 -Wall -c -fmessage-length=0 -o \"src\\%s.o\" \"..\\src\\%s.cpp\""
LINK_COMMAND_PREFIX = "g++ \"-L%s\" -o " + APP_NAME + " "
LINK_FILE_TEMP      = "src\\%s.o "
LIBRARIES           = " -llibopencv_calib3d300 -llibopencv_core300 -llibopencv_features2d300 -llibopencv_flann300 -llibopencv_highgui300 -llibopencv_imgcodecs300 -llibopencv_imgproc300 -llibopencv_ml300 -llibopencv_objdetect300 -llibopencv_photo300 -llibopencv_shape300 -llibopencv_stitching300 -llibopencv_superres300 -llibopencv_video300 -llibopencv_videoio300 -llibopencv_videostab300"

src_files = ["SplitGaussians\\BackgroundGaussian",
             "SplitGaussians\\ForegroundGaussian",
             "SplitGaussians\\Pixel",
             "SplitGaussians\\SplitGaussian",
             "FluxTensor\\FluxTensorMethod",
             "FTSGAlgorithm",
             "Tools\\file_name_generator",
             "Tools\\tests",
             "Tools\\tools",
             "Tools\\window_manager",
             "main"]

#Get Parent Directory Path
os.chdir(os.pardir)
WORKING_PATH = os.getcwd()

#Go to compile dir and compile
os.chdir(WORKING_PATH+SLASH+COMPILE_DIR)
include_path = WORKING_PATH+SLASH+OPENCV_INCLUDES_DIR
library_path = WORKING_PATH+SLASH+OPENCV_LIBS_DIR
link_command = LINK_COMMAND_PREFIX % library_path
for src_file in src_files:
    compile_cmd  = COMPILE_COMMAND % (include_path, src_file, src_file)
    link_command += (LINK_FILE_TEMP % src_file)
    subprocess.call(compile_cmd)
link_command += LIBRARIES
subprocess.call(link_command)

#Copy Exe to Working Path
os.chdir(WORKING_PATH)
shutil.copy2(COMPILE_DIR+APP_NAME, '.')

#Launch Exe
subprocess.call(APP_NAME)
