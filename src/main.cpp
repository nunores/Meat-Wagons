#include "GraphViewer/graphviewer.h"
#include "Menu/menu.h"
#include "Graph.h"
#include "Parse/parse.h"

using namespace std;

Graph<Point> graph;

int main() {
    vector<Prisoner> prisoners;
    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");

    while (true)
    {
        if(showMainMenu(prisoners) == 0)
            break;
    }

    Prisoner::savePrisoners(prisoners);

    GraphViewer *gc = new GraphViewer(600, 600, false);
    gc->createWindow(1000,1000);
    return 0;
}
