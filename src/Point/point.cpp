#include "point.h"

Point::Point(int id, int x, int y) : id(id), x(x), y(y) {}

int Point::getId() const {
    return id;
}

Point::Point() : id(0), x(0), y(0) {

}
