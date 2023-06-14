#include "ROT_Struct.h"

UseStruct::UseStruct() : pSt_(new St) {}

UseStruct::UseStruct(const UseStruct &other) : pSt_(new St(*other.pSt_)) {}

UseStruct &UseStruct::operator=(const UseStruct &other)
{
    if (this != &other)
    {
        *pSt_ = *other.pSt_;
    }
    return *this;
}

UseStruct::~UseStruct()
{
    delete pSt_;
}

void UseStruct::setData(int n, double d)
{
    pSt_->n = n;
    pSt_->d = d;
}

std::ostream &operator<<(std::ostream &out, const UseStruct &u)
{
    out << "n = " << u.pSt_->n << ", d = " << u.pSt_->d << "\n";
    return out;
}