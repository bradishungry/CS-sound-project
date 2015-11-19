/* 
 * File:   main.h
 * Author: bboswell
 *
 * Created on November 10, 2015, 1:27 PM
 */

#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;
class main : public help {
public:
    virtual void fhelp(){
       cout <<  "Soundscape is a series of programs to handle sound" << endl;
       cout << "list of programs are as follows:" << endl;
       cout << "sndinfo - displays file information" << endl;
       cout << "sndcat - adds one sound file to the end of another" << endl;
       cout << "sndmix - changes audio volume of files and mixes them together" << endl;
       cout << "sndgen - creates a sound with a basic attack, decay, sustain, release envelope" << endl;
    }
};
void getInfo();
void startCat();
void startMix();
void startGen();
#endif //MAIN_H_

