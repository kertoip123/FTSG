def getStats(cm):
    """Return the usual stats for a confusion matrix."""
    TP, TN, FP, FN = cm

    recall = 100.0 * TP / (TP + FN)
    specficity = 100.0 * TN / (TN + FP)
    fpr = 100.0 * FP / (FP + TN)
    fnr = 100.0 * FN / (TP + FN)
    pwc = 100.0 * (FN + FP) / (TP + FP + FN + TN)
    precision = 100.0 * TP / (TP + FP)
    fmeasure = 2.0 * (recall * precision) / (recall + precision)
    return recall, specficity, fpr, fnr, pwc, precision, fmeasure