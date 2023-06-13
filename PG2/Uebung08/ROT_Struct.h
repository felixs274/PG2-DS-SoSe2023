#ifndef ROT_STRUCT_H
#define ROT_STRUCT_H
#include <iostream>

struct St {
    int n {};
    double d {};
};
class UseStruct {
    St * pSt_; // Zeiger auf eine Struktur St
    public:
        // hier fehlende Teile einfügen
        void setData(int n, double d);
    friend std::ostream & operator <<
        (std::ostream & ,
            const UseStruct & u);
};
#endif