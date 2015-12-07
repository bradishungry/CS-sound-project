/*
 * File:   filereader.h
 * Author: bboswell
 *
 * Created on November 11, 2015, 12:29 PM
 */

#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>
#include "help.h"

using namespace std;

class filereader : public help {
public:
    filereader();
    filereader(string, int *, int *, int *, int *, int **);
    virtual ~filereader();
    void readFile(string);
    virtual void fhelp() {
        cout << "This program gives out file information for a .cs229 or .wav file" << endl;
        cout << "enter a valid filename after the program name and it will return information from the file" << endl;
        cout << "note that whitespace or # signs will be ignored." << endl;
    }
private:

};

void sampleGetter(ifstream &, int *);

#endif	/* FILEREADER_H */

