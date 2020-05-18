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

void Prisoner::addPrisoner(vector<Prisoner> &prisonersVector){
    string nif_temp;
    int nif;
    string name;
    string age_temp;
    int age;
    string location_temp;
    int location;
    string destination_temp;
    int destination;
    bool found = false;

    clearScreen();

    while(true){
        cout<<"What is the prisoner's NIF?"<<endl;
        getline(cin, nif_temp);

        try{
            nif = stoi(nif_temp);
            if(!checkNif(nif))
                throw exception();

            // TODO: Verificar que não existe ainda no vetor


            if(found){
                clearScreen();
                cout<<"Prisoner with that NIF ais lready on registed " << endl;
            }
            else
                break;
        }

        catch(...){
            clearScreen();
            cout<<"NIF not valid, please try again"<<endl;
        }

    }
    clearScreen();
    cout<<"What is the prisoner's name?"<<endl;
    getline(cin,name);

    cout<<"What is the prisoner's age?"<<endl;
    getline(cin, age_temp);

    age = stoi(age_temp);

    cout<<"What is the prisoner's current location? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, location_temp);

    location = stoi(location_temp);

    cout<<"What is the prisoner's destination? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, destination_temp);

    destination = stoi(destination_temp);


    Prisoner prisoner = Prisoner(nif, name, age, destination, location);

    prisonersVector.push_back(prisoner);

    cout << "Prisoner registed!" << endl;
    enter_to_exit();
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

