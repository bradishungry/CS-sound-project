/*
 * File:   filereader.cpp
 * Author: bboswell
 *
 * Created on November 11, 2015, 12:29 PM
 */

#include "filereader.h"
#include "sndinfo.h"
#include "util.h"
#include "help.h"
#include <iostream>
#include <fstream>
using namespace std;
//pass in argument to read (check if ends in cs229

filereader::filereader() {

}

filereader::filereader(string filename, int * channels, int * bitres, int * samprate, int * samples, int ** sample_array) {
    util u;
    int i;
    ifstream fs(filename.c_str());
    string a;
    i += 1;
    fs>>a;
    a = u.toLow(a);
    if (a.compare("cs229") == 0) { //Check if valid file
      while (!fs.eof()) {
         if (a.compare("samples") == 0) {
            fs>>*samples;
         }
         if (a.compare("channels") == 0) {
            fs>>*channels;
         }
         if (a.compare("bitres") == 0) {
            fs>>*bitres;
         }
         if (a.compare("samplerate") == 0) {
            fs>>*samprate;
         }
         if (a.compare("startdata") == 0){
             if(channels != 0 && bitres != 0 && samprate != 0){
               if(samples != 0){
                  *sample_array = new int[*samples];
                  sampleGetter(fs, *sample_array);
               } else {
                  *sample_array = new int[400];
                  sampleGetter(fs, *sample_array);
               }
               //cout << *sample_array[0];
               break;
             }
         }
         fs>>a;
         a = u.toLow(a);
        }
    } else {
        cout << "Bad File Format" << endl;
    }
}

filereader::~filereader() {
}


void sampleGetter(ifstream &filest, int sample_array[]){
   int index = 0;
   while(!filest.eof()){
      filest>>sample_array[index];
      index += 1;
   }
}
