import subprocess
import os
import shutil
import logging
import time
from src_code_changer import macroSwap
from GCCBuild import gcc_compile
from config import *

if __name__ == "__main__":

    logging.basicConfig(format='%(message)s',level = logging.INFO)
    logging.info("Test runner has started...")
    global_start = time.time()

    #Set Working Path
    os.chdir(os.pardir)
    working_path = os.getcwd()
    logging.info("Working path set to: %s", working_path)

    #Iterate through all test sequences (by category)
    for cat in tests:
        logging.info("Starting to test sequences from category: %s", cat)
        test_seqs = tests[cat]
        for test_seq in test_seqs:
            logging.info("Compiling and testing sequence: %s", test_seq.get_test_name())
            start = time.time()
            macroSwap(test_seq)
            gcc_compile(working_path)
            std_out = subprocess.check_output(COMPILE_DIR+APP_NAME)
            test_seq.add_output(std_out)
            msg = "Test runner has finished to test: %s. Execution time: %f s"
            logging.info(msg, test_seq.get_test_name(), time.time()-start)

    #Save results
    logging.info("Analyzing and storing results to: %s", working_path+OUTPUT_FILE)
    with open(OUTPUT_FILE, 'w') as results:
        for cat in tests:
            test_seqs = tests[cat]
            for test_seq in test_seqs:
                test_seq.std_out_analyze()
                results.write(str(test_seq))

    logging.info("Test runner has finished. Total execution time: %f s", time.time()-global_start)
