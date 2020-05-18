#ifndef SRC_PRISONER_H
#define SRC_PRISONER_H
#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <misc.h>

using namespace std;

class Prisoner {
public:
    Prisoner(int nif, string name, int age, int destination, int location);
    void printPrisoner();
    bool canMove() const;
    void addPrisoner(vector<Prisoner> prisonersVector);
    void buildPrisoner();


        private:
    int nif;
    string name;
    int age;
    int destination;
    int location;
};


#endif //SRC_PRISONER_H
