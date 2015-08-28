//--------------------
// c++ headers
//--------------------
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cstdlib>

using namespace cv;
using namespace std;
#define COLOR_DEPTH 256

int main( int argc, char** argv )
{
    // define variables for the following operation:
    // original - background -> diff -> [selective picking process] -> out
    Mat original, background, diff, out;
    unsigned int i, j;
    float distance, threshold;

    if(argc != 5) {
	      printf("Number of parameters must be 3.\n");
	      printf("example usage: Substract beam.png background.png (INT THRESHOLD) out.png\n");
	      return -1;
	  }

    // first input is original image
    original   = imread(argv[1], 1);
    // cvtColor(original , gray_original , CV_BGR2GRAY);

    // second parameter is background image
    background = imread(argv[2], 1);
    // cvtColor(background , gray_background , CV_BGR2GRAY);

    threshold  = atof(argv[3]);

    // check if images are loaded successfully
    if(!original.data || !background.data) {
        printf("I couldn't read the image(s).\n");
        return -1;
    }

    diff = original - background;

    out = Mat::zeros(diff.rows, diff.cols, CV_8UC3);

    for(i = 0; i < original.rows; i++)
      for(j = 0; j < original.cols; j++) {
            Vec3b pix = diff.at<Vec3b>(i, j);
            distance  =  sqrt(pix[0]*pix[0]+pix[1]*pix[1]+pix[2]*pix[2]);
            if(distance > threshold) {
                out.at<Vec3b>(i, j) = original.at<Vec3b>(i, j);
            }
        }

    // write the image
    imwrite(argv[4], out);

    return 0;
}
