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

//filewriter::filewriter(int * data, int channels, int samprate, int bitres, int samples, ofstream& os) {

//}

filewriter::~filewriter() {
}

void init(int * data, int channels, int samprate, int bitres, int samples, ofstream& os){
   os<<"CS229\n";
   if(samples != 0){
      os<<"Samples   ";
      os<<samples;
      os<<'\n';
   }
   os<<"Channels   ";
   os<<channels;
   os<<'\n';
   os<<"BitRes   ";
   os<<bitres;
   os<<'\n';
   os<<"SampleRate   ";
   os<<samprate;
   os<<'\n';
   os<<"Startdata    ";
   os<<'\n';
   addSamples(os, data, channels, samples);
}
void addSamples(ofstream& ofs, int * data, int chan, int samp){
   for(int i = 0; i < samp; i += 1){
      ofs<<data[i];
      ofs<<" ";
      if((i + 1) % chan == 0){
         ofs<<'\n';
      }
   }
}
