#include "Prisoner.h"

extern vector<Prisoner> prisoners;

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
    cout << location << endl;
    cout << destination << endl;
    cout << "::::::::::" << endl;
}

void Prisoner::printAllPrisoners(){
    for (auto prisoner : prisoners) {
        prisoner.printPrisoner();
    }
}

bool Prisoner::canMove() const {
    return destination != -1;
}

void Prisoner::addPrisoner(){
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
                cout<<"Prisoner with that NIF is already on registed " << endl;
            }
            else
                break;
        }

        catch(...){
            cout<<"NIF not valid, please try again"<<endl;
        }

    }
    cout<<"What is the prisoner's name?"<<endl;
    getline(cin,name);

    cout<<"What is the prisoner's age?"<<endl;
    getline(cin, age_temp);

    age = stoi(age_temp);

    cout<<"What is the prisoner's current location? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, location_temp);

    // TODO: Verificar que ele se encontra numa localização válida

    location = stoi(location_temp);

    cout<<"What is the prisoner's destination? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, destination_temp);

    destination = stoi(destination_temp);


    Prisoner prisoner = Prisoner(nif, name, age, destination, location);

    prisoners.push_back(prisoner);

    cout << "Prisoner registed!" << endl;
    enter_to_exit();
}

void Prisoner::removePrisoner() {
    // Getting the prisoner to remove

    string nif_temp;
    int nif;
    Prisoner prisoner = Prisoner();
    bool found = false;

    while(true){
        cout<<"What is the prisoner's NIF to remove?"<<endl;
        getline(cin, nif_temp);

        try{
            nif = stoi(nif_temp);
            if(!checkNif(nif))
                throw exception();

            // Finding the wanted prisoner
            for(auto it = prisoners.begin(); it != prisoners.end(); it++){
                if(it->nif == nif) {
                    prisoner = *it;
                    found = true;
                    prisoners.erase(it);
                    break;
                }
            }


            if(found){
                cout << "Prisoner removed succesfully" << endl;
                enter_to_exit();
                return;
            }
            else
                throw exception();
        }

        catch(...){
            clearScreen();
            cout<<"NIF not valid, please try again"<<endl;
        }

    }







    // Removing the prisoner
    //prisonersVector.erase(/*iterator*/);
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

int Prisoner::getNif() const {
    return nif;
}

string Prisoner::getName() const {
    return name;
}

int Prisoner::getAge() const {
    return age;
}

int Prisoner::getDestination() const {
    return destination;
}

int Prisoner::getLocation() const {
    return location;
}

void Prisoner::savePrisoners(vector<Prisoner> &prisonersVector){
    ofstream prisonersFile;
    prisonersFile.open("../Files/prisoners.txt");

    int temp = 0;

    for(Prisoner prisoner : prisonersVector){
        temp++;
        prisonersFile << to_string(prisoner.getNif()) << endl;
        prisonersFile << prisoner.getName() << endl;
        prisonersFile << to_string(prisoner.getAge()) << endl;
        prisonersFile << to_string(prisoner.getLocation()) << endl;
        prisonersFile << to_string(prisoner.getDestination()) << endl;

        if(temp == prisonersVector.size())
            prisonersFile << "::::::::::";
        else
            prisonersFile << "::::::::::" << endl;
    }

    prisonersFile.close();

}

ostream &operator<<(ostream &os, const Prisoner &prisoner) {
    os << "nif: " << prisoner.nif << " name: " << prisoner.name << " age: " << prisoner.age << " destination: "
       << prisoner.destination << " location: " << prisoner.location;
    return os;
}

