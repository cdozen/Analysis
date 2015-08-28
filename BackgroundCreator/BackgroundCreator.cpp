#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cstdlib>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    int i;
    Mat input, output;
    for(i = 1; i < argc - 1; i++) {
        printf("Reading %s...\n", argv[i]);
        input  = imread(argv[i], 1);
        input.convertTo(input, CV_32SC3);
        if(i == 1)
           output = Mat::zeros(input.rows, input.cols, CV_32SC3);
        add(output, input, output);
    }
    output = output / (argc - 2);
    imwrite(argv[argc - 1], output);
    return 0;
}
