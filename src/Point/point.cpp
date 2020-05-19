#include "point.h"

Point::Point(int id, double x, double y) : id(id), x(x), y(y) {}

int Point::getId() const {
    return id;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

Point::Point() : id(0), x(0), y(0) {

}

Point::Point(int id) : id(id), x(0), y(0){}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "id: " << point.id << " x: " << point.x << " y: " << point.y;
    return os;
}

bool Point::operator==(const Point &rhs) const {
    return id == rhs.id;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}
