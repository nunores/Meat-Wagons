#include "GraphViewer/graphviewer.h"
#include "Menu/menu.h"
#include "Graph.h"
#include "Parse/parse.h"

using namespace std;

Graph<Point> graph;
vector<Prisoner> prisoners;

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
