#include <iostream>
#include <cstdlib>

#include "PG-1-3_UZ_dec2Bin.h"

using std::cin;
using std::cout;
using std::endl;

template <typename T>
void shiftLeft(T *toShift)
{
    *toShift <<= sizeof(T) * 8 - 1;
}

template <typename RawType, typename VarType>
void loop(RawType mask, VarType var)
{
    for (int n = sizeof(VarType) * 8 - 1; n >= 0; mask >>= 1, n--)
    {
        if (var & mask)
            cout << "1";
        else
            cout << "0";
        if (n % 8 == 0)
            cout << "|";
    }
    cout << endl;
}

template <typename RawType>
void loop(RawType mask, float var)
{
    //! sanity check
    static_assert(sizeof(RawType) == sizeof(var));

    RawType *convVar = reinterpret_cast<RawType *>(&var);

    for (int n = sizeof(float) * 8 - 1; n >= 0; mask >>= 1, n--)
    {
        if (mask & *convVar)
            cout << "1";
        else
            cout << "0";
        if (n % 31 == 0 || n % 23 == 0)
            cout << "|";
    }
    cout << endl;
}

template <typename RawType>
void loop(RawType mask, double var)
{
    //! sanity check
    static_assert(sizeof(RawType) == sizeof(var));

    RawType *convVar = reinterpret_cast<RawType *>(&var);

    for (int n = sizeof(RawType) * 8 - 1; n >= 0; mask >>= 1, n--)
    {
        if (mask & *convVar)
            cout << "1";
        else
            cout << "0";
        if (n % 63 == 0 || n % 52 == 0)
            cout << "|";
    }
    cout << endl;
}

void dec2bin(int nChoice, char sz[])
{
    unsigned char uc, c = 1;
    shiftLeft(&c);

    unsigned int ui, i = 1;
    shiftLeft(&i);

    unsigned long ul, l = 1;
    shiftLeft(&l);

    unsigned long long ull, ll = 1;
    shiftLeft(&ll);

    float f;
    double d;

    cout << "\n|";
    switch (nChoice)
    {
    case 0:
    case 1:
        uc = strtoul(sz, nullptr, 10);
        loop(c, uc);
        break;
    case 2:
    case 3:
        ui = strtoul(sz, nullptr, 10);
        loop(i, ui);
        break;
    case 4:
    case 5:
        ul = strtoul(sz, nullptr, 10);
        loop(l, ul);
        break;
    case 6:
    case 7:
        ull = strtoull(sz, nullptr, 10);
        loop(ll, ull);
        break;
    case 8:
        f = strtof(sz, nullptr);
        loop(i, f);
        break;
    case 9:
        d = strtod(sz, nullptr);
        loop(ll, d);
        break;
    }
}
