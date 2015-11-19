/* 
 * File:   filewriter.cpp
 * Author: bboswell
 * 
 * Created on November 19, 2015, 12:41 PM
 */

#include <fstream>
#include "filewriter.h"
using namespace std;
filewriter::filewriter() {
}

filewriter::filewriter(string filename) {
    ifstream fp(filename.c_str());
}

filewriter::~filewriter() {
}

