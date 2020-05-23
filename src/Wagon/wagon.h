//
// Created by jmgg on 21/05/20.
//

#ifndef MEAT_WAGONS_WAGON_H
#define MEAT_WAGONS_WAGON_H

using namespace std;

class Wagon {
private:
    int dest;
public:
    static int capacity;
    static double cost_per_dist;
    int ocupation = 0;
    static double average_speed;
    double dist = 0;

    Wagon(int dest);

    void setOcupation(int ocupation);

    void setDist(double dist);

    int getOcupation() const;

    double getDist() const;

    int getDest() const;
};

#endif //MEAT_WAGONS_WAGON_H
