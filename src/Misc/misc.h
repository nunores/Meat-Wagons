#ifndef MEAT_WAGONS_MISC_H
#define MEAT_WAGONS_MISC_H

#pragma once

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <cmath>

#define min2(a, b) ((a) < (b) ? (a) : (b))
using namespace std;


void clearScreen();

void clearBuffer();

bool strIsNumber(string str);

bool strIsChar(string str);

void enter_to_exit();

bool checkNif(int nif);

#endif //MEAT_WAGONS_MISC_H
