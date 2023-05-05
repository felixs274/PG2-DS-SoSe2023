#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

enum class EyeColor {Blue, Brown, Green};

struct PStruct{
    std::string s_; // surname
    EyeColor e_;
    double h_;
    bool g_; // gender 0 = male, 1 = female
    std::ostream& print(std::ostream&);
};

std::ostream & operator <<(std::ostream &, PStruct &);

#endif // PERSON_H