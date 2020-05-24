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

    if(saveMenu() == 1)
    {
        Prisoner::savePrisoners(prisoners);
    }

    return 0;
}
