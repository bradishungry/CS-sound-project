/*
 * File:   filewriter.h
 * Author: bboswell
 *
 * Created on November 19, 2015, 12:41 PM
 */

#ifndef FILEWRITER_H
#define	FILEWRITER_H
#include <iostream>
#include <fstream>
using namespace std;
class filewriter {
public:
    filewriter();
    virtual ~filewriter();
private:

};
void init(int *, int, int, int, int, ofstream&);
void addSamples(ofstream&, int *, int, int);

#endif	// FILEWRITER_H_
