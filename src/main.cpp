#include "GraphViewer/graphviewer.h"
#include "Menu/menu.h"
#include "Graph.h"
#include "Parse/parse.h"


using namespace std;

int main() {
    vector<Prisoner> prisoners;
    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");
    showMainMenu(prisoners);
    Graph<int> graph;

    parseNodes("../Mapas/PortugalMaps/Coimbra/nodes_x_y_coimbra.txt", &graph);

    GraphViewer *gc = new GraphViewer(600, 600, false);
    gc->createWindow(1000,1000);
    return 0;
}
