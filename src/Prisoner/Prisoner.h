#ifndef SRC_PRISONER_H
#define SRC_PRISONER_H
#include <iostream>
#include <locale>
#include <string>
using namespace std;

class Prisoner {
public:
    Prisoner(int nif, string name, int age, int destination, int location);
    void printPrisoner();
    bool canMove() const;

private:
    int nif;
    string name;
    int age;
    int destination;
    int location;
};


#endif //SRC_PRISONER_H
