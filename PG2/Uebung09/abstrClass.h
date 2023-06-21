#ifndef ABSTRCLASS_H
#define ABSTRCLASS_H

#include <iostream>

// Point
typedef struct Point {
    double x_{};
    double y_{};
} P;

// Figure
class Figure {
    protected: 
        P center_{};
    public: 
        Figure(const P &);
        virtual ~Figure();
        virtual std::ostream & print1(std::ostream &) const = 0;
        virtual void print2(std::ostream &) const;
};

std::ostream & operator << (std::ostream &, const Figure &);

// Line
class Line : public Figure {
    public:
        Line(const P &);
        virtual std::ostream & print1(std::ostream &) const override;
};

// Ellipse
class Ellipse : public Figure {
    public: 
        Ellipse(const P &);
        virtual std::ostream & print1(std::ostream &) const override final;
};

// Circle
class Circle : public Ellipse {
    public: 
        Circle(const P &);
        virtual void print2(std::ostream &) const override;
};

#endif // ABSTRCLASS_H