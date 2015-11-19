/* 
 * File:   wav_reader.cpp
 * Author: bboswell
 * 
 * Created on November 17, 2015, 4:58 PM
 */

#include <iosfwd>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "wav_reader.h"
using namespace std;

wav_reader::wav_reader() {
}

wav_reader::wav_reader(string wavs) {
    string fstring;
    unsigned char buffer[120];
    unsigned int data;
    ifstream wavfs;
    wavfs.open(wavs.c_str(), ios::in | ios::binary);
    wavfs.read((char *)buffer, 8);
//    wavfs.read(buffer, 4);
    //    wavfs.read(buffer, 4);
    //        data = (unsigned int) buffer[0] << 24 + buffer[1] << 16 + buffer[2] << 8 + buffer[3];
//    cout << (int)buffer[5] << endl;
        printf("%c", buffer[2]);
}

wav_reader::~wav_reader() {
}

