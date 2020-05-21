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

void parseNodes(const string& path_to_nodes);
void parseEdges(const string& path_to_edges);
void parseTags(const string& path_to_tags, int for_1, int for_2);

void parseViseu();
double getLowestX();
double getHighestX();
double getLowestY();
double getHighestY();
void parsePorto();
void parseCoimbra();

void preProcessing(int source_ID);


#endif //MEAT_WAGONS_PARSE_H
