#include "abstrClass.h"

// Figure
Figure::Figure(const P &center) : center_(center){};

Figure::~Figure(){};

void Figure::print2(std::ostream &out) const
{
    out << "Figure::print2" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Figure &fig)
{
    return fig.print1(out);
}

// Line
Line::Line(const P &center) : Figure(center){};

std::ostream &Line::print1(std::ostream &out) const
{
    out << "Center Line: (" << center_.x_ << ", " << center_.y_ << ")" << std::endl;
    return out;
}

// Ellipse
Ellipse::Ellipse(const P &center) : Figure(center){};

std::ostream &Ellipse::print1(std::ostream &out) const
{
    out << "Center Ellipse: (" << center_.x_ << ", " << center_.y_ << ")" << std::endl;
    return out;
}

// Circle
Circle::Circle(const P &center) : Ellipse(center) {}

void Circle::print2(std::ostream &out) const
{
    out << "Center Circle: (" << center_.x_ << ", " << center_.y_ << ")" << std::endl;
}