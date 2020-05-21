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

    int getNif() const;
    string getName() const;
    int getAge() const;
    int getDestination() const;
    int getLocation() const;


    void printPrisoner();
    bool canMove() const;
    static void printAllPrisoners();
    static void addPrisoner();
    static void removePrisoner();

    static vector<Prisoner> initPrisoners(string file);
    static void savePrisoners(vector<Prisoner> &prisonersVector);


private:
    int nif;
    string name;
    int age;
    int destination;
    int location;
};


#endif //SRC_PRISONER_H
