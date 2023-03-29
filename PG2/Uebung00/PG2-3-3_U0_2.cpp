#include <iostream>

/*
windows Compilierung

1. Preprocessor
2. Assembler
3. Object file
5. generating the executable 

g++ -E datasize.cpp -o outwin/datasize.ii
g++ -S outwin/datasize.ii -o outwin/datasize.s
g++ -c outwin/datasize.s  -o outwin/datasize.o
g++ outwin/datasize.o -o outwin/datasize.exe
outwin/datasize.exe

gleiches für linux

g++ -E datasize.cpp -o outlinux/datasize.ii
g++ -S outlinux/datasize.ii -o outlinux/datasize.s
g++ -c outlinux/datasize.s  -o outlinux/datasize.o
g++ outlinux/datasize.o -o outlinux/datasize
outlinux/datasize
*/

int main()
{
    std::cout << "Datasizes of the following types:" << std::endl;
    std::cout << "sizeof int: " << sizeof(int) << std::endl;
    std::cout << "sizeof long: " << sizeof(long) << std::endl;
    std::cout << "sizeof int32_t: " << sizeof(int32_t) << std::endl;
    std::cout << "sizeof int64_t: " << sizeof(int64_t) << std::endl;
}