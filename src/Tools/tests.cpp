#include "tests.hpp"
#include <iostream>

uint64_t metrics[] = {0,0,0,0};

void count_coefficients(Mat & result, Mat & gt_frame)
{
    const uchar * result_pixel_ptr;
    const uchar * gt_pixel_ptr;

    for(int row = 0; row < result.rows; ++row)
    {
    	//cout<<"row " << row <<endl;
        result_pixel_ptr = result.ptr(row);
        gt_pixel_ptr = gt_frame.ptr(row);
        for(int col = 0; col < result.cols; ++col)
        {
        	uchar gt = *gt_pixel_ptr++;
        	uchar res = *result_pixel_ptr++;

        	if(gt == 85)
        		continue;
            bool gt_mask = (gt >= 170) ? true : false;
        	bool res_mask = (res == 255) ? true : false;

        	if(gt_mask && res_mask)
        		metrics[0]++;
        	else if(!gt_mask && !res_mask)
        		metrics[1]++;
        	else if(!gt_mask && res_mask)
        		metrics[2]++;
        	else if(gt_mask && !res_mask)
        		metrics[3]++;
        }
    }
}

void print_metrics(){

	long tp = metrics[0];
	long tn = metrics[1];
	long fp = metrics[2];
	long fn = metrics[3];

	COUT<<"TOTAL: "<<"(TP = "<<tp<<", TN ="<<tn<<", FP = "<<fp<<", FN = "<<fn<<")"<<endl;
//    double recall = (double)tp/(tp+fn);
//    double specificity = (double) tn/(tn+fp);
//    double FPR = (double) fp/(fp+tn);
//    double FNR = (double) fn/(tp+fn);
//    double PWC = (double) 100*(fn+fp)/(tp+fn+fp+tn);
//    double precision = (double)tp/(tp+fp);
//    double F1 = (2*precision*recall)/(precision+recall);
//
//    cout << "tp: " <<tp<< endl;
//    cout << "tn: " <<tn<< endl;
//    cout << "fp: " <<fp<< endl;
//    cout << "fn: " <<fn<< endl;
//    cout << /*"Recall = " <<*/ recall << endl;
//    cout << /*"Specificity = " <<*/ specificity << endl;
//    cout << /*"FPR = " <<*/ FPR << endl;
//    cout << /*"FNR = " <<*/ FNR << endl;
//    cout << /*"PWC = " <<*/ PWC << endl;
//    cout << /*"F1 = " <<*/ F1 << endl;
//    cout << /*"Precision = " <<*/ precision << endl;
//    cout << endl;
}

