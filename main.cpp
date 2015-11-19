/* 
 * File:   main.cpp
 * Author: bboswell
 *
 * Created on November 10, 2015, 11:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

#include "filereader.h"
#include "util.h"
#include "main.h"
#include "wav_reader.h"

/*
 * 
 */

void getInfo(string f1, bool help) {
    string ftype;
    float len;
    if (help == true) {
        filereader * f = new filereader();
        f->fhelp();
        exit(1);
    }
    string fname = f1.substr(0, f1.find_last_of('.'));
    cout << fname << endl;
    ftype = f1.substr(f1.find_last_of('.'));
    if(ftype.compare(".wav") == 0){
        wav_reader * w = new wav_reader(f1);
    } else {
        cout << ftype << endl; //found find last of from /u/graphitemaster on stack overflow
        filereader * f = new filereader(f1);
        len = f->calculateLength(f->samples, f->samprate);
        cout << "File Length: ";
        cout << len << endl;
    }
}

void startCat() {
}

void startMix() {
}

void startGen() {
}

int main(int argc, char** argv) {
    util u;
    if (argv[1] == NULL) {
        cout << "Error 1: no program entered" << endl;
        exit(1);
    }
    string upper = argv[1];
    string h;
    bool help = false;
    upper = u.toLow(upper);
    if(upper.compare("-h") == 0){
       cout <<  "Soundscape is a series of programs to handle sound" << endl;
       cout << "list of programs are as follows:" << endl;
       cout << "sndinfo - displays file information" << endl;
       cout << "sndcat - adds one sound file to the end of another" << endl;
       cout << "sndmix - changes audio volume of files and mixes them together" << endl;
       cout << "sndgen - creates a sound with a basic attack, decay, sustain, release envelope" << endl;    
       exit(1);
    }
    for (int i = 0; i < argc; i++) {
        h = argv[i];
        if (h.compare("-h") == 0) {
            help = true;
        }
    }
    if (upper.compare("sndinfo") == 0) {
        cout << "File Information\n----------------" << endl;
        getInfo(argv[2], help);
    } else if (upper.compare("sndcat") == 0) {
        startCat();
        cout << "cat\n";
    } else if (upper.compare("sndmix") == 0) {
        startMix();
        cout << "mix\n";
    } else if (upper.compare("sndgen") == 0) {
        startGen();
        cout << "gen\n";
    } else {
        cout << "error: invalid program name\nflag -h for a list of commands\n";
    }
    return 0;
}

