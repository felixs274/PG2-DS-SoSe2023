#include <iostream>
#include <cstdlib>
#include "PG-1-3_UZ_dec2Bin.h"

constexpr std::size_t LEN = 21; // longest possible input including '\0'

using std::cin;
using std::cout;
using std::endl;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}

int main()
{
    int choice;
    char sz[LEN];
    while (true)
    {
        clearScreen();
        cout << "Datatypes\n---------\n";
        cout << "0 - unsigned char\n";
        cout << "1 - signed char\n";
        cout << "2 - unsigned int\n";
        cout << "3 - signed int\n";
        cout << "4 - unsigned long\n";
        cout << "5 - signed long\n";
        cout << "6 - unsigned long long\n";
        cout << "7 - signed long long\n\n";
        cout << "8 - float\n";
        cout << "9 - double\n\n";
        cout << "10 - end\n";
        cout << "\nYour choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "unsigned char number: ";
            break;
        case 1:
            cout << "signed char number: ";
            break;
        case 2:
            cout << "unsigned int: ";
            break;
        case 3:
            cout << "signed int: ";
            break;
        case 4:
            cout << "unsigned long: ";
            break;
        case 5:
            cout << "signed long: ";
            break;
        case 6:
            cout << "unsigned long long: ";
            break;
        case 7:
            cout << "signed long long: ";
            break;
        case 8:
            cout << "float: ";
            break;
        case 9:
            cout << "double: ";
            break;
        case 10:
            cout << "\nProgram terminated!\n";
            return 1;
        default:
            cout << "\nWrong entry - program terminated!\n";
            return 1;
        }
        cin >> sz;
        dec2bin(choice, sz);
        cout << "\nPlease press <RETURN>";
        cin.get();
        cin.get();
    }

    return 0;
}
