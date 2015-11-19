/* 
 * File:   filereader.cpp
 * Author: bboswell
 * 
 * Created on November 11, 2015, 12:29 PM
 */

#include "filereader.h"
#include "main.h"
#include "util.h"
#include "help.h"
#include <iostream>
#include <fstream>
using namespace std;
//pass in argument to read (check if ends in cs229

filereader::filereader() {

}

filereader::filereader(string filename) {
    util u;
    samples;
    int i;
    bool fformat = false;
    int channels;
    int bitres;
    samprate;
    ifstream fs(filename.c_str());
    string a;
    while (fformat == false) {
        i += 1;
        fs>>a;
        a = u.toLow(a);
        if (a.compare("cs229") == 0) { //Check if valid file
            while (!fs.eof()) {
                if (a.compare("samples") == 0) {
                    fs>>samples;
                }
                if (a.compare("channels") == 0) {
                    fs>>channels;
                }
                if (a.compare("bitres") == 0) {
                    fs>>bitres;
                }
                if (a.compare("samplerate") == 0) {
                    fs>>samprate;
                }
                fs>>a;
                a = u.toLow(a);
                //        process(a);
                fformat = true;
            }
        } else {
            if(fs.eof()){
                cout << "Bad File Format" << endl;
                break;
            }
        }
    }
    if (samples != 0) {
        cout << "Samples: ";
        cout << samples << endl;
    }
    if (channels != 0) {
        cout << "Channels: ";        
        cout << channels << endl;
    }
    if (bitres != 0) {
        cout << "Bitres: ";                
        cout << bitres << endl;
    }
    if (samprate != 0) {
        cout << "Sample Rate: ";                
        cout << samprate << endl;
    }
}

filereader::~filereader() {
}

float filereader::calculateLength(int samp, int rate) {
    float len;
    len = (float) samp / (float) rate;
    return len;
}

void readFile(string filename) {
}

void process(string a) {
}
