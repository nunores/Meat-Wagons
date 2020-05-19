#ifndef MEAT_WAGONS_POINT_H
#define MEAT_WAGONS_POINT_H


#include <ostream>

class Point {
private:
    int id;
    int x, y;

public:
    Point();
    Point(int id, int x, int y);

    int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;
};


#endif //MEAT_WAGONS_POINT_H
