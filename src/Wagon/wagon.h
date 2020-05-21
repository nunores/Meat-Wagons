//
// Created by jmgg on 21/05/20.
//

#ifndef MEAT_WAGONS_WAGON_H
#define MEAT_WAGONS_WAGON_H

using namespace std;

class Wagon {
private:
    int id;
    int capacity;
    double cost_per_dist;
    int ocupation;
    int average_speed;
    int dist = 0;

public:
    Wagon(int id, int capacity, double costPerDist, int ocupation, int averageSpeed);

    void setCapacity(int capacity);

    void setCostPerDist(double costPerDist);

    void setOcupation(int ocupation);

    void setAverageSpeed(int averageSpeed);

    int getId() const;

    int getCapacity() const;

    double getCostPerDist() const;

    int getOcupation() const;

    int getAverageSpeed() const;

};

#endif //MEAT_WAGONS_WAGON_H
