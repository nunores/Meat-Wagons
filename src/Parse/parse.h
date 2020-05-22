#ifndef MEAT_WAGONS_PARSE_H
#define MEAT_WAGONS_PARSE_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <Graph.h>
#include "../Point/point.h"
#include <cmath>
#include "../Prisoner/Prisoner.h"

using namespace std;

void parseNodes(const string& path_to_nodes);
void parseEdges(const string& path_to_edges);
void parseTags(const string& path_to_tags, int for_1, int for_2);

void parseViseu(int dest, vector<Prisoner> &vector_prisoners);
void parseViseu2(vector<Prisoner> &vector_prisoners);
void parsePorto(int dest, vector<Prisoner> &vector_prisoners);
void parsePorto2(vector<Prisoner> &vector_prisoners);
void parseCoimbra(int dest, vector<Prisoner> &vector_prisoners);
void parseCoimbra2(vector<Prisoner> &vector_prisoners);



double getLowestX();
double getHighestX();
double getLowestY();
double getHighestY();

void preProcessingViseu(int source_ID);
void preProcessingPorto(int source_ID);
void preProcessingCoimbra(int source_ID);

bool isInDestinations(vector<int> &destinations, int destination);
vector<vector<Prisoner>> parsePrisonersViseu(vector<Prisoner> & all_prisoners);
vector<vector<Prisoner>> parsePrisonersPorto(vector<Prisoner> & all_prisoners);
vector<vector<Prisoner>> parsePrisonersCoimbra(vector<Prisoner> & all_prisoners);



#endif //MEAT_WAGONS_PARSE_H
