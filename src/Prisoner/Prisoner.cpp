#include "Prisoner.h"

Prisoner::Prisoner(int nif, string name, int age, int destination, int location) {
    this->nif = nif;
    this->name = name;
    this->age = age;
    this->destination = destination;
    this->location = location;
}

void Prisoner::printPrisoner() {
    cout << nif << endl;
    cout << name << endl;
    cout << age << endl;
    cout << destination << endl;
    cout << location << endl;
    cout << "::::::::::" << endl;
}

bool Prisoner::canMove() const {
    return destination != -1;
}


