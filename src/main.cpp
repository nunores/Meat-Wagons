#include "GraphViewer/graphviewer.h"
#include "Prisoner/Prisoner.h"
#include "Menu/menu.h"
#include "Misc/misc.h"


using namespace std;

int main() {
    vector<Prisoner> prisoners;
    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");
    showMainMenu();
    GraphViewer *gc = new GraphViewer(600, 600, false);
    gc->createWindow(1000,1000);
    return 0;
}
