#include "parse.h"
#include "../Point/point.h"

void parseNodes(const string& path_to_nodes, Graph<int> *graph){
    string temp;
    Point point = Point();

    ifstream nodes_file;
    nodes_file.open(path_to_nodes);

    getline(nodes_file, temp); // Discarded number of nodes

    while(!nodes_file.eof()){
        getline(nodes_file, temp);
        point = Point(0, 0 ,0);
    }


}