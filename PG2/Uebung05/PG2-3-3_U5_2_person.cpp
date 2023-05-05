#include "person.h"

std::ostream& operator <<(std::ostream& stream, PStruct& obj2print)
{
    obj2print.print(stream);
    return stream;
}


std::ostream& operator <<(std::ostream& stream, EyeColor& color)
{
    switch(color)
    {
    case EyeColor::Blue:
        stream << "EyeColor::Blue";
        break;
    case EyeColor::Brown:
        stream << "EyeColor::Brown";
        break;
    case EyeColor::Green:
        stream << "EyeColor::Green";
        break;
    default:
        stream << "unkown color";
        break;
    }
    return stream;
}

std::ostream& PStruct::print(std::ostream& stream)
{
    stream << "PStruct {\"" << s_ << "\", " << e_ << ", " << h_ << ", " << g_ << "};";
    return stream;
}
