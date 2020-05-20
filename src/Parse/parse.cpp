#include "parse.h"

extern Graph<Point> graph;

void parseNodes(const string& path_to_nodes){
    graph = Graph<Point>();

    string temp;
    int id;
    double x, y;
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

        y = stod(temp.substr(0, temp.find_first_of(')')));
        point = Point(id, x ,y);
        graph.addVertex(point);
    }
}

double getLowestX()
{
    double x = 99999999;
    for (unsigned i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getInfo().getX() < x)
        {
            x = graph.getVertexSet()[i]->getInfo().getX();
        }
    }
    return x;
}

double getHighestX()
{
    double x = -99999999;
    for (unsigned i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getInfo().getX() > x)
        {
            x = graph.getVertexSet()[i]->getInfo().getX();
        }
    }
    return x;
}

double getLowestY()
{
    double y = 99999999;
    for (unsigned i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getInfo().getY() < y)
        {
            y = graph.getVertexSet()[i]->getInfo().getY();
        }
    }
    return y;
}

double getHighestY()
{
    double y = -99999999;
    for (unsigned i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getInfo().getY() > y)
        {
            y = graph.getVertexSet()[i]->getInfo().getY();
        }
    }
    return y;
}

void parseViseu(){
    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt");
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt", &graph);
}

// Do strictly after nodes
void parseEdges(const string& path_to_edges, Graph<Point> *graph){
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

        x1 = graph->findVertex(point1)->getInfo().getX();
        x2 = graph->findVertex(point2)->getInfo().getX();
        y1 = graph->findVertex(point1)->getInfo().getY();
        y2 = graph->findVertex(point2)->getInfo().getY();

        weight = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));


        graph->addEdge(id1, id2, weight);
        graph->addEdge(id2, id1, weight);

    }

}