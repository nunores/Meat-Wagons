#ifndef MEAT_WAGONS_POINT_H
#define MEAT_WAGONS_POINT_H


class Point {
private:
    int id;
    int x, y;

public:
    Point();
    Point(int id, int x, int y);

    int getId() const;
};


#endif //MEAT_WAGONS_POINT_H
