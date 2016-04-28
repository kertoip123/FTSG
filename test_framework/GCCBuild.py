import subprocess
import os
import shutil
from config import *

COMPILE_COMMAND     = "g++ \"-I%s\" -O0 -g3 -w -c -fmessage-length=0 -o \"src/%s.o\" \"../src/%s.cpp\""
LINK_COMMAND_PREFIX = "g++ \"-L%s\" -w -o " + APP_NAME + " "
LINK_FILE_TEMP      = "src/%s.o "

def gcc_compile(working_path):
    os.chdir(working_path+SLASH+COMPILE_DIR)
    include_path = working_path+SLASH+OPENCV_INCLUDES_DIR
    library_path = working_path+SLASH+OPENCV_LIBS_DIR
    link_command = LINK_COMMAND_PREFIX % library_path
    for src_file in src_files:
        compile_cmd  = COMPILE_COMMAND % (include_path, src_file, src_file)
        link_command += (LINK_FILE_TEMP % src_file)
        subprocess.call(compile_cmd)
    link_command += LIBRARIES
    subprocess.call(link_command)
    os.chdir(working_path)

