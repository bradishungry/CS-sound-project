/* 
 * File:   util.cpp
 * Author: bboswell
 * 
 * Created on November 14, 2015, 1:49 PM
 */

#include "util.h"

util::util() {
}

util::~util() {
}

string util::toLow(string upper) {
    for (int i = 0; i < upper.length(); i += 1) {
        upper[i] = tolower(upper[i]);
    }
    return upper;
}