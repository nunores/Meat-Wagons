
#include "Prisoner/Prisoner.h"
#include "Menu/menu.h"
#include "Misc/misc.h"


using namespace std;

int main() {
    vector<Prisoner> prisoners;
    prisoners = Prisoner::initPrisoners("../Files/prisoners.txt");
    showMainMenu();
    Prisoner::addPrisoner(prisoners);
    for(Prisoner prisoner : prisoners)
    {
        prisoner.printPrisoner();
    }
    return 0;
}
