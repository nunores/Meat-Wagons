#ifndef MEAT_WAGONS_PARSE_H
#define MEAT_WAGONS_PARSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <Graph.h>
#include "../Point/point.h"
#include <cmath>

using namespace std;

void parseNodes(const string& path_to_nodes, Graph<Point> *graph);
void parseEdges(const string& path_to_edges, Graph<Point> *graph);
void parseViseu();
double getLowestX();
double getHighestX();
double getLowestY();
double getHighestY();



#endif //MEAT_WAGONS_PARSE_H
