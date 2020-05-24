#include "parse.h"
#include "../Wagon/wagon.h"
#include <climits>

extern Graph<Point> graph;
extern vector<int> viseu_tags;
extern vector<int> porto_tags;
extern vector<int> coimbra_tags;
extern vector<Wagon> wagons;

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

vector<vector<Prisoner>> parsePrisonersViseu(vector<Prisoner> & all_prisoners){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(viseu_tags, temp_destination)){
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

vector<vector<Prisoner>> parsePrisonersViseu3(vector<Prisoner> & all_prisoners, int capacity){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;
    int ocupation = 1;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(viseu_tags, temp_destination)){
            destinations.push_back(temp_destination);
            temp.push_back(all_prisoners.at(i));
            for (int n = i+1; n < all_prisoners.size(); ++n) {
                if(all_prisoners.at(n).getDestination() == temp_destination) {
                    if (ocupation < capacity)
                    {
                        temp.push_back(all_prisoners.at(n));
                        ocupation++;
                    }
                    else
                    {
                        res.push_back(temp);
                        temp.clear();
                        temp.push_back(all_prisoners.at(n));
                        ocupation = 0;
                        ocupation++;
                    }

                }
            }
            ocupation = 1;
            res.push_back(temp);
            temp.clear();
        }
    }

    return res;
}

vector<vector<Prisoner>> parsePrisonersPorto(vector<Prisoner> & all_prisoners){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(porto_tags, temp_destination)){
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

vector<vector<Prisoner>> parsePrisonersPorto3(vector<Prisoner> & all_prisoners, int capacity){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;
    int ocupation = 1;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(porto_tags, temp_destination)){
            destinations.push_back(temp_destination);
            temp.push_back(all_prisoners.at(i));
            for (int n = i+1; n < all_prisoners.size(); ++n) {
                if(all_prisoners.at(n).getDestination() == temp_destination) {
                    if (ocupation < capacity)
                    {
                        temp.push_back(all_prisoners.at(n));
                        ocupation++;
                    }
                    else
                    {
                        res.push_back(temp);
                        temp.clear();
                        temp.push_back(all_prisoners.at(n));
                        ocupation = 0;
                        ocupation++;
                    }

                }
            }
            ocupation = 1;
            res.push_back(temp);
            temp.clear();
        }
    }

    return res;
}

vector<vector<Prisoner>> parsePrisonersCoimbra(vector<Prisoner> & all_prisoners){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(coimbra_tags, temp_destination)){
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

vector<vector<Prisoner>> parsePrisonersCoimbra3(vector<Prisoner> & all_prisoners, int capacity){
    vector<vector<Prisoner>> res;

    vector<int> destinations;
    int temp_destination;
    int ocupation = 1;

    vector<Prisoner> temp;


    for (int i = 0; i < all_prisoners.size(); i++) {
        temp_destination = all_prisoners.at(i).getDestination();
        if(!isInDestinations(destinations, temp_destination) && temp_destination != -1 && isInDestinations(coimbra_tags, temp_destination)){
            destinations.push_back(temp_destination);
            temp.push_back(all_prisoners.at(i));
            for (int n = i+1; n < all_prisoners.size(); ++n) {
                if(all_prisoners.at(n).getDestination() == temp_destination) {
                    if (ocupation < capacity)
                    {
                        temp.push_back(all_prisoners.at(n));
                        ocupation++;
                    }
                    else
                    {
                        res.push_back(temp);
                        temp.clear();
                        temp.push_back(all_prisoners.at(n));
                        ocupation = 0;
                        ocupation++;
                    }

                }
            }
            ocupation = 1;
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
    wagons.clear();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessingViseu(374376834);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;
    Wagon wagon = Wagon(dest);


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
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
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
        wagon_dist += temp_dist;
        src = prisioneiros[index_remove];
        prisioneiros.erase(prisioneiros.begin()+index_remove);
        for (int i = 0; i < final_point_vector.size(); i++)
        {
            graph.findVertex(final_point_vector[i].getId())->setYellow();
        }
    }
    temp_dist = 0;
    if (peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        for (int i = 0; i < point_vector.size(); i++) {
            if (i != 0)
                temp_dist += sqrt(pow((point_vector[i].getX() - point_vector[i-1].getX()), 2) + pow((point_vector[i].getY() - point_vector[i-1].getY()), 2));

            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagon_dist += temp_dist;
        wagon.setDist(wagon_dist);
        wagons.push_back(wagon);
    }
}

void parseViseu2(vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();
    wagons.clear();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessingViseu(374376834);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersViseu(vector_prisoners);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 374376834;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 374376834;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }
            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }
}

void parsePorto(int dest, vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();
    wagons.clear();
    Wagon wagon = Wagon(dest);
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
    parseTags("../Mapas/meat_wagon_tags_porto.txt", 4, 101);

    preProcessingPorto(299610576);

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
    int src = 299610576;
    int index_remove;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
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
        wagon_dist += temp_dist;
        src = prisioneiros[index_remove];
        prisioneiros.erase(prisioneiros.begin()+index_remove);
        for (int i = 0; i < final_point_vector.size(); i++)
        {
            graph.findVertex(final_point_vector[i].getId())->setYellow();
        }
    }
    temp_dist = 0;
    if (peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        for (int i = 0; i < point_vector.size(); i++) {
            if (i != 0)
                temp_dist += sqrt(pow((point_vector[i].getX() - point_vector[i-1].getX()), 2) + pow((point_vector[i].getY() - point_vector[i-1].getY()), 2));

            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagon_dist += temp_dist;
        wagon.setDist(wagon_dist);
        wagons.push_back(wagon);
    }
}

void parsePorto2(vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();
    wagons.clear();
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
    parseTags("../Mapas/meat_wagon_tags_porto.txt", 4, 101);

    preProcessingPorto(299610576);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersPorto(vector_prisoners);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 299610576;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 299610576;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }
            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }
}



void parseCoimbra(int dest, vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();
    wagons.clear();
    Wagon wagon = Wagon(dest);
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 1104700202);
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
    parseTags("../Mapas/meat_wagon_tags_coimbra.txt", 4, 212);

    preProcessingCoimbra(1104700202);

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
    int src = 1104700202;
    int index_remove;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
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
        wagon_dist += temp_dist;
        src = prisioneiros[index_remove];
        prisioneiros.erase(prisioneiros.begin()+index_remove);
        for (int i = 0; i < final_point_vector.size(); i++)
        {
            graph.findVertex(final_point_vector[i].getId())->setYellow();
        }
    }
    temp_dist = 0;
    if (peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        for (int i = 0; i < point_vector.size(); i++) {
            if (i != 0)
                temp_dist += sqrt(pow((point_vector[i].getX() - point_vector[i-1].getX()), 2) + pow((point_vector[i].getY() - point_vector[i-1].getY()), 2));

            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagon_dist += temp_dist;
        wagon.setDist(wagon_dist);
        wagons.push_back(wagon);
    }
}


void parseCoimbra2(vector<Prisoner> &vector_prisoners){
    graph = Graph<Point>();
    wagons.clear();
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 1104700202);
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
    parseTags("../Mapas/meat_wagon_tags_coimbra.txt", 4, 212);

    preProcessingCoimbra(1104700202);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersCoimbra(vector_prisoners);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 1104700202;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 1104700202;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }
            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }
}

void parseViseu3(vector<Prisoner> &vector_prisoners) {
    graph = Graph<Point>();
    wagons.clear();

    parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessingViseu(374376834);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersViseu3(vector_prisoners, Wagon::capacity);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 374376834;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 374376834;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }

            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }
}

void parsePorto3(vector<Prisoner> &vector_prisoners) {
    graph = Graph<Point>();
    wagons.clear();
    parseNodes("../Mapas/PortugalMaps/Porto/nodes_x_y_porto.txt", 299610576);
    parseEdges("../Mapas/PortugalMaps/Porto/edges_porto.txt");
    parseTags("../Mapas/meat_wagon_tags_porto.txt", 4, 101);

    preProcessingPorto(299610576);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersPorto3(vector_prisoners, Wagon::capacity);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 299610576;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 299610576;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }
            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }

}

void parseCoimbra3(vector<Prisoner> &vector_prisoners) {
    graph = Graph<Point>();
    wagons.clear();
    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", 1104700202);
    parseEdges("../Mapas/PortugalMaps/Coimbra/edges_coimbra.txt");
    parseTags("../Mapas/meat_wagon_tags_coimbra.txt", 4, 212);

    preProcessingCoimbra(1104700202);
    vector<int> prisioneiros;
    int i = -1;
    bool peopleMoved = false;

    vector<vector<Prisoner>> all_prisoners = parsePrisonersCoimbra3(vector_prisoners, Wagon::capacity);

    for ( int m = 0; m < all_prisoners.size(); m++) {
        i = -1;
        for (Prisoner prisoner : vector_prisoners) {
            i++;
            if (prisoner.getDestination() == all_prisoners[m][0].getDestination()) {
                prisioneiros.push_back(prisoner.getLocation());
                vector_prisoners.at(i).setLocation(all_prisoners[m][0].getDestination());
                vector_prisoners.at(i).setDestination(-1);
                peopleMoved = true;
            }
        }
    }

    for (int i = 0; i < all_prisoners.size(); i++)
    {
        Wagon wagon = Wagon(all_prisoners[i][0].getDestination());
        wagons.push_back(wagon);
    }

    vector<Point> point_vector;
    vector<Point> final_point_vector;
    int src = 1104700202;
    int index_remove;
    int dest;
    double dist = INT_MAX;
    double temp_dist = 0;
    double wagon_dist = 0;
    for (int z = 0; z < all_prisoners.size(); z++) {
        src = 1104700202;
        wagon_dist = 0;
        while(!all_prisoners[z].empty()) {
            for (int i = 0; i < all_prisoners[z].size(); i++) {
                dest = all_prisoners[z][i].getDestination();
                temp_dist = 0;
                graph.dijkstraShortestPath(src);
                point_vector = graph.getPath(src, all_prisoners[z][i].getLocation());
                for (int n = 0; n < point_vector.size(); n++) {
                    if (n != 0)
                        temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                          pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
                    if (temp_dist < dist && n == point_vector.size() - 1) {
                        dist = temp_dist;
                        index_remove = i;
                        final_point_vector = point_vector;
                    }
                }
            }
            wagon_dist += temp_dist;
            dist = INT_MAX;
            src = all_prisoners[z][index_remove].getLocation();
            all_prisoners[z].erase(all_prisoners[z].begin() + index_remove);
            for (int i = 0; i < final_point_vector.size(); i++) {
                graph.findVertex(final_point_vector[i].getId())->setYellow();
            }
        }
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, dest);
        temp_dist = 0;
        for (int n = 0; n < point_vector.size(); n++) {
            if (n != 0)
                temp_dist += sqrt(pow((point_vector[n].getX() - point_vector[n - 1].getX()), 2) +
                                  pow((point_vector[n].getY() - point_vector[n - 1].getY()), 2));
        }
        wagon_dist += temp_dist;
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
        wagons[z].setDist(wagon_dist);
        wagon_dist = 0;
    }
    if (!peopleMoved) {
        graph.dijkstraShortestPath(src);
        point_vector = graph.getPath(src, src);
        for (int i = 0; i < point_vector.size(); i++) {
            graph.findVertex(point_vector[i].getId())->setYellow();
        }
    }

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

void preProcessingViseu(int source_ID){
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
    for (int i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getLocation())
        {
            viseu_tags.push_back(graph.getVertexSet()[i]->getInfo().getId());
        }
    }
}

void preProcessingPorto(int source_ID){
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
    for (int i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getLocation())
        {
            porto_tags.push_back(graph.getVertexSet()[i]->getInfo().getId());
        }
    }
}

void preProcessingCoimbra(int source_ID){
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
    for (int i = 0; i < graph.getNumVertex(); i++)
    {
        if (graph.getVertexSet()[i]->getLocation())
        {
            coimbra_tags.push_back(graph.getVertexSet()[i]->getInfo().getId());
        }
    }
}
