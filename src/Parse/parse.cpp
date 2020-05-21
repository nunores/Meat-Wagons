#include "parse.h"

extern Graph<Point> graph;

void parseNodes(const string& path_to_nodes, int source){
    string temp;
    int id;
    int src = 0;
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
        if (id == source)
        {
            point.setSource();
            src = id;
        }
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
    graph = Graph<Point>();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt");
    vector<Vertex<Point>*> temp_graph = graph.mybfs(374376834);
    vector<Edge<Point>> edge_vector;
    Graph<Point> empty_graph = Graph<Point>();
    for (int i = 0; i < temp_graph.size(); i++)
    {
        for (int n = 0; n < temp_graph[i]->getAdj().size(); n++)
        {
            Edge<Point> edge = Edge<Point>(temp_graph[i], temp_graph[i]->getAdj()[n].getDestPointer(), temp_graph[i]->getAdj()[n].getWeight());
            edge_vector.push_back(edge);
        }
    }
    for (int i = 0; i < temp_graph.size(); i++)
    {
        empty_graph.addVertex(temp_graph[i]->getInfo());
        if (temp_graph[i]->getLocation())
        {
            empty_graph.findVertex(temp_graph[i]->getInfo())->setIsLocation(true);
        }
    }
    for (int i = 0; i < temp_graph.size(); i++)
    {
        for (int n = 0; n < temp_graph[i]->getAdj().size(); n++)
        {
            empty_graph.addEdge(temp_graph[i]->getInfo(), temp_graph[i]->getAdj()[n].getDest().getInfo(), temp_graph[i]->getAdj()[n].getWeight());
        }
    }
    graph = empty_graph;
}

void parsePorto(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
    //parseTags("../Mapas/TagExamples/Porto/t08_tags_porto.txt");

}

void parseCoimbra(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 714520129);
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
    //parseTags("../Mapas/TagExamples/Coimbra/t08_tags_coimbra.txt");

}

void parseTags(const string& path_to_tags){
    string temp;
    int id;

    ifstream tags_file;
    tags_file.open(path_to_tags);

    getline(tags_file, temp);

    while(!tags_file.eof()){

        for (int i = 0; i < 4; ++i) {
            getline(tags_file, temp);
            getline(tags_file, temp);
            for (int j = 0; j < 61; ++j) {
                getline(tags_file, temp);
                Point point = Point(stoi(temp));
                graph.findVertex(point)->setIsLocation(true);
            }
        }
    }
}

// Do strictly after nodes
void parseEdges(const string& path_to_edges){
    string temp;
    int id1 = 0, id2 = 0;
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int weight = 0;

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