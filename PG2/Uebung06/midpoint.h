#ifndef MIDPOINT_H
#define MIDPOINT_H

#include <iostream>


struct Point {
    double x_;
    double y_;
    double z_;
    Point(double, double, double); // delegating constructor
    Point(double, double); // forwarding constructor
    Point(double); // forwarding constructor
};

std::ostream & operator << (std::ostream & , Point & );

class Midpoint {
    Point p1_;
    Point p2_;
    public:
        Midpoint(Point, Point);
        Point getMidpoint();
        // prints coordinates of center
        friend std::ostream & operator << (std::ostream & , Midpoint & );
};

class Distance {
    Midpoint m1_;
    Midpoint m2_;
    public:
        Distance(Midpoint, Midpoint);
        double getDistance();
        std::ostream & print(std::ostream & );
};

std::ostream & operator << (std::ostream & , Distance & );

#endif // MIDPOINT_H