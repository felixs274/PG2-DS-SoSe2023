#include "PG2-3-3_U8_1_ROT_Struct.h"

int main()
{
    UseStruct st1;
    std::cout << "st1: " << st1;

    UseStruct st2;
    st2.setData(42, 3.14);
    std::cout << "st2: " << st2;

    UseStruct st3{st2};
    std::cout << "st3 (Copy of st2): " << st3;

    UseStruct st4;
    st4.setData(99, 1.23);
    std::cout << "st4: " << st4;
    st1 = st4;
    std::cout << "st1 (overwritten by st4): " << st1;

    return 0;
}