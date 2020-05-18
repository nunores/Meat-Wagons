#ifndef SRC_PRISONER_H
#define SRC_PRISONER_H
#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <../Misc/misc.h>

using namespace std;

class Prisoner {
public:
    Prisoner(int nif, string name, int age, int destination, int location);
    Prisoner();

    void setNif(int nif);

    void setName(const string &name);

    void setAge(int age);

    void setDestination(int destination);

    void setLocation(int location);

    void printPrisoner();
    bool canMove() const;
    static void addPrisoner(vector<Prisoner> &prisonersVector);
    static vector<Prisoner> initPrisoners(string file);


private:
    int nif;
    string name;
    int age;
    int destination;
    int location;
};


#endif //SRC_PRISONER_H
