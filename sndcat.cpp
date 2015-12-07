#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#include "filereader.h"
#include "filewriter.h"

int main(int argc, char ** argv){
   int length = argc;
   int bitres = 0;
   int samples = 0;
   int channels = 0;
   int samprate = 0;
   int chancheck = 0;
   int * sample_array;
   ofstream of("output.txt");
   filewriter * fw = new filewriter();
   string *fnames = new string[argc - 1];
   for(int i = 0; i < argc - 1; i += 1){
      fnames[i] = argv[i + 1];
      //if swatches handle
   }
   for(int i = 0; i < argc - 1; i += 1){
      filereader * f = new filereader(fnames[i], &channels, &bitres, &samprate, &samples, &sample_array);
      if(i == 0){
         init(sample_array, channels, samprate, bitres, samples, of);
         chancheck = channels;
      } else {
         if(chancheck != channels){
            cout << "File channels must be equal!" << endl;
            return 1;
         }
         addSamples(of, sample_array, channels, samples);
      }
      delete f;
   }
   delete fw;
   delete [] fnames;
   return 0;
}
