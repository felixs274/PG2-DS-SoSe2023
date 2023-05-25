#include "midpoint.h"
#include <cmath>



Point::Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}
Point::Point(double x, double y) : Point(x, y, 0.0) {}
Point::Point(double x) : Point(x, 0.0, 0.0) {}

std::ostream & operator <<(std::ostream & out, Point & point) {
    out << "(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ")";
    return out;
}




Midpoint::Midpoint(Point p1, Point p2) : p1_(p1), p2_(p2) {}

Point Midpoint::getMidpoint() {
    double x = (p1_.x_ + p2_.x_) / 2.0;
    double y = (p1_.y_ + p2_.y_) / 2.0;
    double z = (p1_.z_ + p2_.z_) / 2.0;
    return Point(x, y, z);
}

std::ostream & operator <<(std::ostream & out, Midpoint & midpoint) {
    Point center = midpoint.getMidpoint();
    out << "(" << center.x_ << ", " << center.y_ << ", " << center.z_ << ")";
    return out;
}




Distance::Distance(Midpoint m1, Midpoint m2) : m1_(m1), m2_(m2) {}

double Distance::getDistance() {
    Point midpoint1 = m1_.getMidpoint();
    Point midpoint2 = m2_.getMidpoint();
    double x = std::pow((midpoint1.x_ - midpoint2.x_), 2);
    double y = std::pow((midpoint1.y_ - midpoint2.y_), 2);
    double z = std::pow((midpoint1.z_ - midpoint2.z_), 2);
    double dist = std::sqrt(x + y + z);
    return dist;
}

std::ostream & operator <<(std::ostream & out, Distance & dist) {
    out << dist.getDistance();
    return out;
}