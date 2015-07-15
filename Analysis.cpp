#include <stdio.h>
#include <cv.h>
#include <highgui.h>

using namespace cv;

#define COLOR_DEPTH 256

int main( int argc, char** argv )
{
    uchar value;
    unsigned int histogram[COLOR_DEPTH];
    unsigned int i, j;

    Mat image;
    // read image
    image = imread(argv[1], 1);
    if( argc != 2 || !image.data ){
        printf( "No image data \n" );
        return -1;
    }

    // convert image into grayscale image
    cvtColor(image, image, CV_BGR2GRAY);

    // clean histogram array
    for(i = 0; i < COLOR_DEPTH; i ++) histogram[i] = 0;

    // scan image
    for(i = 0; i < image.rows; i++)
        for(j = 0; j < image.cols; j++) {
            value = *image.ptr<uchar>(i, j);
            histogram[value] ++;
        }

    // print histogram
    for(i = 0; i < COLOR_DEPTH; i++) printf("%d\t%d\n", i, histogram[i]);

    return 0;
}
