#include <cv.h>
#include <highgui.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#define TIMEPIX_WIDTH  256
#define TIMEPIX_HEIGHT 256
#define TIMEPIX_MAX    (TIMEPIX_WIDTH*TIMEPIX_HEIGHT)

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
    vector<unsigned int> fromTimePix;
    unsigned char * ptr;
    int i, j;
    float max;

    // check if the number of arguments are enough
    if(argc < 3) {
        cout << "Not enough parameter.\n";
        return 1;
    }

    // open the TimePix text file
    ifstream file(argv[1], std::ios::in);
    if(file.fail()) {
        cout << "I couldn't read the text file: " << argv[1];
        return 1;
    }

    // loop each value
    string value;
    int counter = 0;
    while(!file.eof() && counter < TIMEPIX_MAX) {
        file >> value;
        fromTimePix.push_back(stoi(value));
        counter ++;
    }

    max = 1;
    // find the max for the normalization
    for(int i = 0; i < TIMEPIX_HEIGHT; i ++) {
        for(int j = 0; j < TIMEPIX_WIDTH; j++) {
            if(fromTimePix[i * TIMEPIX_WIDTH + j] > max) max = ptr[j];
        }
    }
                         

    Mat output;
    output = Mat::zeros(TIMEPIX_WIDTH, TIMEPIX_HEIGHT, CV_8UC1);
    for(int i = 0; i < TIMEPIX_HEIGHT; i ++) {
        ptr = output.ptr<unsigned char>(i);
        for(int j = 0; j < TIMEPIX_WIDTH; j++) {
            ptr[j] = fromTimePix[i * TIMEPIX_WIDTH + j] * (255/max);
        }
    }

    imwrite(argv[2], output);

    return 0;
}
