import re
from tempfile import mkstemp
from shutil import move
from os import remove, close
from test import Test

TEST_FILE          = "src/Tools/tests.hpp"

def macroSwap(test):
    test_id  = test.get_test_id()
    macro_re = re.compile("#define TEST_GROUP.*\d{1,2}")
    subst    = "#define TEST_GROUP\t%d" % test_id
    replace(TEST_FILE, macro_re, subst)

def replace(file_path, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    with open(abs_path,'w') as new_file:
        with open(file_path) as old_file:
            for line in old_file:
                new_file.write(re.sub(pattern, subst, line))
    close(fh)
    #Remove original file
    remove(file_path)
    #Move new file
    move(abs_path, file_path)