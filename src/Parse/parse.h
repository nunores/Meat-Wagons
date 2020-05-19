#ifndef MEAT_WAGONS_PARSE_H
#define MEAT_WAGONS_PARSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <Graph.h>
#include "../Point/point.h"

using namespace std;

void parseNodes(const string& path_to_nodes, Graph<Point> *graph);


#endif //MEAT_WAGONS_PARSE_H
