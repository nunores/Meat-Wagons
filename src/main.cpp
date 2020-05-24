#include "GraphViewer/graphviewer.h"
#include "Menu/menu.h"
#include "Graph.h"
#include "Parse/parse.h"
#include "Wagon/wagon.h"

using namespace std;

Graph<Point> graph;
vector<Prisoner> prisoners;
vector<int> viseu_tags;
vector<int> porto_tags;
vector<int> coimbra_tags;
vector<Wagon> wagons;

int main() {

    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");

    while (true)
    {
        if(showMainMenu() == 0)
            break;
    }

    for (Wagon wagon: wagons)
    {
        cout << wagon.getDest() << endl;
        cout << wagon.getDist() << endl;
        cout << "#######" << endl;
    }

    /*parseNodes("../Mapas/PortugalMaps/Viseu/nodes_x_y_viseu.txt", 374376834);
    parseEdges("../Mapas/PortugalMaps/Viseu/edges_viseu.txt");
    parseTags("../Mapas/meat_wagon_tags_viseu.txt", 4, 61);

    preProcessingViseu(374376834);
    vector<vector<Prisoner>> zaa = parsePrisonersViseu3(prisoners, 3);

    for (int i = 0; i < zaa.size(); i++)
    {
        for (int n = 0; n < zaa[i].size(); n++)
        {
            zaa[i][n].printPrisoner();
        }
        cout << "#######" << endl;
    }*/

    //Prisoner::savePrisoners(prisoners);


    return 0;
}
