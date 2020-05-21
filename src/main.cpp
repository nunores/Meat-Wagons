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

    vector<vector<Prisoner>> temp = parsePrisoners(prisoners);


    for (int i = 0; i < temp.size(); ++i) {
        cout << "Vector: " << i << endl;
        for (int j = 0; j < temp.at(i).size(); ++j) {
            cout << temp.at(i).at(j) << endl;
        }
    }

    Prisoner::savePrisoners(prisoners);


    return 0;
}
