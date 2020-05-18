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

void Prisoner::addPrisoner(vector<Prisoner> prisonersVector){
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
        cout<<"what is the prisoner's NIF?"<<endl;
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

    cout<<"what is the prisoner's age?"<<endl;
    getline(cin, age_temp);

    age = stoi(age_temp);

    cout<<"what is the prisoner's age?"<<endl;
    getline(cin, age_temp);

    cout<<"what is the prisoner's current location? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, location_temp);

    location = stoi(location_temp);


    cout<<"what is the prisoner's destination? Please insert the corresponding node ID or -1 if not applicable"<<endl;
    getline(cin, destination_temp);

    destination = stoi(destination_temp);


    Prisoner prisoner = Prisoner(nif, name, age, destination, location);

    prisonersVector.push_back(prisoner);

    cout << "Prisoner registed!" << endl;
    enter_to_exit();
}

