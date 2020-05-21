#include "parse.h"
#include <climits>

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

vector<vector<Prisoner>> parsePrisoners(vector<Prisoner> & all_prisoners){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination)){
            destinations.push_back(temp_destination);
            temp.push_back(all_prisoners.at(i));
            for (int n = i+1; n < all_prisoners.size(); ++n) {
                if(all_prisoners.at(n).getDestination() == temp_destination)
                    temp.push_back(all_prisoners.at(n));
            }
            res.push_back(temp);
            temp.clear();
        }
    }

    return res;
}


bool isInDestinations(vector<int> &destinations, int destination){
    for(int i = 0; i < destinations.size(); i++){
        if(destination == destinations.at(i))
            return true;
    }

    return false;
}



void parseViseu(int dest, vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessing(374376834);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;


    for (Prisoner prisoner : vector_prisoners)
    {
        i++;
        if (prisoner.getDestination() == dest)
        {
            prisioneiros.push_back(prisoner.getLocation());
            vector_prisoners.at(i).setLocation(dest);
            vector_prisoners.at(i).setDestination(-1);
            peopleMoved = true;
        }
    }
    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 374376834;
    int index_remove;
    int dist = INT_MAX;
    int temp_dist = 0;
    while (!prisioneiros.empty()) {
        for (int i = 0; i < prisioneiros.size(); i++) {
            temp_dist = 0;
            graph.dijkstraShortestPath(src);
            point_vector = graph.getPath(src, prisioneiros[i]);
            for (int n = 0; n < point_vector.size(); n++) {
                if (n != 0)
                    temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n-1].getX()), 2) + pow((point_vector[n].getY() - point_vector[n-1].getY()), 2));
                if (temp_dist < dist && n == point_vector.size() - 1) {
                    dist = temp_dist;
                    index_remove = i;
                    final_point_vector = point_vector;
                }
            }
        }
        dist = INT_MAX;
        src = prisioneiros[index_remove];
        prisioneiros.erase(prisioneiros.begin()+index_remove);
        for (int i = 0; i < final_point_vector.size(); i++)
        {
            graph.findVertex(final_point_vector[i].getId())->setYellow();
        }
    }
    if (peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }
}

void parseViseu2(vector<Prisoner> &vector_prisoners){
/*    graph = Graph<Point>();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessing(374376834);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 374376834;
    int index_remove;
    int dist = INT_MAX;
    int temp_dist = 0;
    while (!prisioneiros.empty()) {
        for (int i = 0; i < prisioneiros.size(); i++) {
            temp_dist = 0;
            graph.dijkstraShortestPath(src);
            point_vector = graph.getPath(src, prisioneiros[i]);
            for (int n = 0; n < point_vector.size(); n++) {
                if (n != 0)
                    temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n-1].getX()), 2) + pow((point_vector[n].getY() - point_vector[n-1].getY()), 2));
                if (temp_dist < dist && n == point_vector.size() - 1) {
                    dist = temp_dist;
                    index_remove = i;
                    final_point_vector = point_vector;
                }
            }
        }
        dist = INT_MAX;
        src = prisioneiros[index_remove];
        prisioneiros.erase(prisioneiros.begin()+index_remove);
        for (int i = 0; i < final_point_vector.size(); i++)
        {
            graph.findVertex(final_point_vector[i].getId())->setYellow();
        }
    }
    if (peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }*/
}

void parsePorto(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
    parseTags("../Mapas/meat_wagon_tags_porto.txt", 4, 101);

    preProcessing(299610576);

}

void parseCoimbra(){
    graph = Graph<Point>();
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 1104700202);
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
    parseTags("../Mapas/meat_wagon_tags_coimbra.txt", 4, 212);

    preProcessing(1104700202);
}

void parseTags(const string& path_to_tags, int for_1, int for_2){
    string temp;
    int id;

    ifstream tags_file;
    tags_file.open(path_to_tags);

    getline(tags_file, temp);

    while(!tags_file.eof()){

        for (int i = 0; i < for_1; ++i) {
            getline(tags_file, temp);
            getline(tags_file, temp);
            for (int j = 0; j < for_2; ++j) {
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

void preProcessing(int source_ID){
    vector<Vertex<Point>*> temp_graph = graph.mybfs(source_ID);
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