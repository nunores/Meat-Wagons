#ifndef MEAT_WAGONS_MISC_H
#define MEAT_WAGONS_MISC_H


#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <cmath>

#include "../Point/point.h"
#include "Graph.h"
#include <graphviewer.h>

using namespace std;

void clearScreen();

void clearBuffer();

bool strIsNumber(string str);

bool strIsChar(string str);

void enter_to_exit();

bool checkNif(int nif);

GraphViewer* createGraph();

#endif //MEAT_WAGONS_MISC_H
