#ifndef SRC_PRISONER_H
#define SRC_PRISONER_H
#include <string>
using namespace std;

class Prisoner {
public:
    Prisoner(int nif, const string &name, int age, int destination, int location);

private:
    int nif;
    string name;
    int age;
    int destination;
    int location;
};

Prisoner::Prisoner(int nif, const string &name, int age, int destination, int location){
    
}


#endif //SRC_PRISONER_H
