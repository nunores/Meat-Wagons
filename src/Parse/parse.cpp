#include "parse.h"

extern Graph<Point> graph;

void parseNodes(const string& path_to_nodes){
    string temp;
    int id;
    float x, y;
    Point point = Point();

    ifstream nodes_file;
    nodes_file.open(path_to_nodes);

    getline(nodes_file, temp); // Discarded number of nodes

    while(!nodes_file.eof()){
        getline(nodes_file, temp);
        id = stoi(temp.substr(1, temp.find_first_of(',')));

        temp = temp.substr(temp.find_first_of(',')+2);

        x = stod(temp.substr(0, temp.find_first_of(',')));
        temp = temp.substr(temp.find_first_of(',')+2);

        y = stod(temp.substr(0, temp.find_first_of(',')));

        point = Point(id, x ,y);
        graph.addVertex(point);

    }

}

void parseViseu(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt");
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
}

void parsePorto(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt");
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
}

void parseCoimbra(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt");
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
}

// Do strictly after nodes
void parseEdges(const string& path_to_edges){
    string temp;
    int id1, id2;
    float x1, x2, y1, y2;
    int weight;

    ifstream nodes_file;
    nodes_file.open(path_to_edges);

    getline(nodes_file, temp); // Discarded number of edges

    while(!nodes_file.eof()){
        getline(nodes_file, temp);
        id1 = stoi(temp.substr(1, temp.find_first_of(',')));

        temp = temp.substr(temp.find_first_of(',')+1);

        id2 = stoi(temp.substr(1, temp.find_first_of(')')));

        Point point1 = Point(id1);
        Point point2 = Point(id2);

        x1 = graph.findVertex(point1)->getInfo().getX();
        x2 = graph.findVertex(point2)->getInfo().getX();
        y1 = graph.findVertex(point1)->getInfo().getY();
        y2 = graph.findVertex(point2)->getInfo().getY();

        weight = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));


        graph.addEdge(id1, id2, weight);
        graph.addEdge(id2, id1, weight);

    }

}