#include "wagon.h"


Wagon::Wagon(int id, int capacity, double costPerDist, int ocupation, int averageSpeed) {
    this->id = id;
    this->capacity = capacity;
    this->cost_per_dist = costPerDist;
    this->average_speed = averageSpeed;
    this->ocupation = ocupation;
}

void Wagon::setCapacity(int capacity) {
    Wagon::capacity = capacity;
}

void Wagon::setCostPerDist(double costPerDist) {
    cost_per_dist = costPerDist;
}

void Wagon::setOcupation(int ocupation) {
    Wagon::ocupation = ocupation;
}

void Wagon::setAverageSpeed(int averageSpeed) {
    average_speed = averageSpeed;
}

int Wagon::getId() const {
    return id;
}

int Wagon::getCapacity() const {
    return capacity;
}

double Wagon::getCostPerDist() const {
    return cost_per_dist;
}

int Wagon::getOcupation() const {
    return ocupation;
}

int Wagon::getAverageSpeed() const {
    return average_speed;
}












