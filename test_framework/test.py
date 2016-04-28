import re
from stats import getStats

class Test(object):

    def __init__(self, test_name, test_id):
        self._test_name = test_name
        self._test_id   = test_id
        self._output    = str("")

    def get_test_id(self):
        return self._test_id

    def get_test_name(self):
        return self._test_name

    def add_output(self, output):
        self._output = output
    
    def std_out_analyze(self):
        pattern_raw_out = '(TP = %d, TN = %d, FP = %d, FN = %d)\n'
        pattern_coef_out = '(Re = %.2f%%, Sp = %.2f%%, FPR = %.2f%%, FNR = %.2f%%, PWC = %.2f%%, Precision = %.2f%%, F-Measure = %.2f%%)\n'
        cm_str = re.findall(r'\d+', self._output)
        cm = []
        for item in cm_str:
            cm.append(float(item))
        recall, specficity, fpr, fnr, pwc, precision, fmeasure = getStats(cm)
        self._output =  pattern_raw_out % tuple(cm)
        self._output += pattern_coef_out % (recall, specficity, fpr, fnr, pwc, precision, fmeasure)

    def __str__(self):
        return self._test_name + "\n" + self._output

if __name__ == "__main__":
    test = Test("highway", 0)
    test.add_output("TOTAL: (TP = 6020321, TN =85920110, FP = 669625, FN = 1853944)")
    test.std_out_analyze()
    print(test)