#ifndef MEAT_WAGONS_MENU_H
#define MEAT_WAGONS_MENU_H
#include "../Misc/misc.h"
#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <sstream>
#include <fstream>

#include <Prisoner.h>


using namespace std;

int showMainMenu();
int choseOption(int options);
int showTransportMenu();
int showMapChoice();
int showDestinationMenu();

#endif //MEAT_WAGONS_MENU_H


