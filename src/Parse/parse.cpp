#include "parse.h"

void parseNodes(const string& path_to_nodes, Graph<Point> *graph){
    string temp;
    int id, x, y;
    Point point = Point();

    ifstream nodes_file;
    nodes_file.open(path_to_nodes);

    getline(nodes_file, temp); // Discarded number of nodes

    while(!nodes_file.eof()){
        getline(nodes_file, temp);
        id = stoi(temp.substr(1, temp.find_first_of(',')));

        temp = temp.substr(temp.find_first_of(',')+2);

        x = stoi(temp.substr(0, temp.find_first_of(',')));
        temp = temp.substr(temp.find_first_of(',')+2);

        y = stoi(temp.substr(0, temp.find_first_of(',')));

        point = Point(id, x ,y);
    }

    graph->addVertex(point);



}