#include "wagon.h"


Wagon::Wagon(int dest) {
    this->dest = dest;
}

int Wagon::capacity = 3;
double Wagon::cost_per_dist = 1.2;
double Wagon::average_speed = 13.8;

void Wagon::setOcupation(int ocupation) {
    Wagon::ocupation = ocupation;
}

int Wagon::getOcupation() const {
    return ocupation;
}

double Wagon::getDist() const {
    return  dist;
}

void Wagon::setDist(double dist) {
    this->dist = dist;
}

int Wagon::getDest() const {
    return dest;
}












