#include "GraphViewer/graphviewer.h"
#include "Menu/menu.h"
#include "Graph.h"
#include "Parse/parse.h"

using namespace std;

Graph<Point> graph;
vector<Prisoner> prisoners;
vector<int> viseu_tags;
vector<int> porto_tags;
vector<int> coimbra_tags;

int main() {

    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");

    while (true)
    {
        if(showMainMenu() == 0)
            break;
    }

    Prisoner::savePrisoners(prisoners);


    return 0;
}
