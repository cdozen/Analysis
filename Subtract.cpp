//--------------------
// c++ headers
//--------------------
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;
#define COLOR_DEPTH 256

int main( int argc, char** argv )
{
    // define variables for the following operation:
    // original - background -> diff
    Mat original, background, diff;

    if(argc != 4) {
	      printf("Number of parameters must be 3.\n");
	      printf("example usage: Substract beam.png background.png out.png\n");
	      return -1;
	  }
	  
	  // first input is original image
	  original   = imread(argv[1], 1);
	  
	  // second parameter is background image
	  background = imread(argv[2], 1);

    // check if images are loaded successfully
    if(!original.data || !background.data) {
        printf("I couldn't read the image(s).\n");
        return -1;
    }

    // subtrack images
    diff = original - background;

    // write the image
    imwrite(argv[4], diff);
    
    return 0;
}
