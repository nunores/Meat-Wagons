#ifndef MEAT_WAGONS_POINT_H
#define MEAT_WAGONS_POINT_H


#include <ostream>

class Point {
private:
    int id;
    double x, y;

public:
    Point();
    Point(int id, double x, double y);

    Point(int id);

    int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    double getX() const;

    double getY() const;
};


#endif //MEAT_WAGONS_POINT_H
