#include "Prisoner.h"

Prisoner::Prisoner(int nif, string name, int age, int destination, int location) {
    this->nif = nif;
    this->name = name;
    this->age = age;
    this->destination = destination;
    this->location = location;
}

Prisoner::Prisoner(){
    this->nif = -1;
    this->name = "";
    this->age = -1;
    this->destination = -1;
    this->location = -1;
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

void Prisoner::buildPrisoner(){
    clearScreen();

    

}

void Prisoner::addPrisoner(vector<Prisoner> prisonersVector){
    // clearScreen();

}

void Prisoner::setNif(int nif) {
    this->nif = nif;
}

void Prisoner::setName(const string &name) {
    this->name = name;
}

void Prisoner::setAge(int age) {
    this->age = age;
}

void Prisoner::setDestination(int destination) {
    this->destination = destination;
}

void Prisoner::setLocation(int location) {
    this->location = location;
}

vector<Prisoner> Prisoner::initPrisoners(string file){
    vector<Prisoner> prisoners;
    ifstream prisonersFile;
    prisonersFile.open(file);
    string line;
    while(!prisonersFile.eof())
    {
        Prisoner prisoner = Prisoner();
        getline(prisonersFile, line);
        prisoner.setNif(stoi(line));
        getline(prisonersFile, line);
        prisoner.setName(line);
        getline(prisonersFile, line);
        prisoner.setAge(stoi(line));
        getline(prisonersFile, line);
        prisoner.setLocation(stoi(line));
        getline(prisonersFile, line);
        prisoner.setDestination(stoi(line));
        prisoners.push_back(prisoner);
        getline(prisonersFile, line);
    }
    return prisoners;
}
