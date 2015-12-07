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
#include "sndinfo.h"
#include "wav_reader.h"

/*
 *
 */

void getInfo(string f1, bool help) {
   int channels = 0;
   int bitres = 0;
   int samprate = 0;
   int samples = 0;
   int * sample_array;
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
      filereader * f = new filereader(f1, &channels, &bitres, &samprate, &samples, &sample_array);
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


   len = calculateLength(samples, samprate);
   cout << "File Length: ";
   cout << len << endl;
}

float calculateLength(int samp, int rate) {
    float len;
    len = (float) samp / (float) rate;
    return len;
}

void startCat() {
}

void startMix() {
}

void startGen() {
}

int main(int argc, char** argv) {
   util u;
   string upper = argv[1];
   string h;
   bool help = false;
   upper = u.toLow(upper);
   if(upper.compare("-h") == 0){
      cout <<  "Soundscape is a series of programs to handle sound" << endl;
      cout << "sndinfo - displays file information" << endl;
      exit(1);
   }
   for (int i = 0; i < argc; i++) {
      h = argv[i];
      if (h.compare("-h") == 0) {
         help = true;
      }
   }
   cout << "File Information\n----------------" << endl;
   getInfo(argv[1], help);
   return 0;
}

