#include <iostream>
#include <cstdlib>

#define LEN 21 // longest possible input including '\0'

using std::cout; using std::cin; using std::endl;

void dec2bin(int, char[]);
void clearScreen();

int main() {
    int choice;
    char sz[LEN];
    while (true) {
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
        switch (choice) {
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
void dec2bin(int nChoice, char sz[]) {
    unsigned char uc, c = 1;
    c <<= sizeof(char) * 8 - 1;
    unsigned int ui, i = 1, * pi = nullptr;
    i <<= sizeof(int) * 8 - 1;
    unsigned long ul, l = 1;
    l <<= sizeof(long) * 8 - 1;
    unsigned long long ull, ll = 1, * pll = nullptr;
    ll <<= sizeof(long long) * 8 - 1;
    float f;
    double d;
    int n;
    cout << "\n|";
    switch (nChoice) {
    case 0:
    case 1:
        uc = strtoul(sz, nullptr, 10);
        for (n = sizeof(char) * 8 - 1; n >= 0; c >>= 1, n--) {
            if (c & uc) cout << "1";
            else cout << "0";
            if (n % 8 == 0) cout << "|";
        }
        cout << endl;
        break;
    case 2:
    case 3:
        ui = strtoul(sz, nullptr, 10);
        for (n = sizeof(int) * 8 - 1; n >= 0; i >>= 1, n--) {
            if (i & ui) cout << "1";
            else cout << "0";
            if (n % 8 == 0) cout << "|";
        }
        cout << endl;
        break;
    case 4:
    case 5:
        ul = strtoul(sz, nullptr, 10);
        for (n = sizeof(long) * 8 - 1; n >= 0; l >>= 1, n--) {
            if (l & ul) cout << "1";
            else cout << "0";
            if (n % 8 == 0) cout << "|";
        }
        cout << endl;
        break;
    case 6:
    case 7:
        ull = strtoull(sz, nullptr, 10);
        for (n = sizeof(long long) * 8 - 1; n >= 0; ll >>= 1, n--) {
            if (ll & ull) cout << "1";
            else cout << "0";
            if (n % 8 == 0) cout << "|";
        }
        cout << endl;
        break;
    case 8:
        f = strtof(sz, nullptr);
        pi = reinterpret_cast < unsigned int * > ( & f);
        i = 1;
        i <<= sizeof(int) * 8 - 1;
        for (n = sizeof(float) * 8 - 1; n >= 0; i >>= 1, n--) {
            if (i & * pi) cout << "1";
            else cout << "0";
            if (n % 31 == 0 || n % 23 == 0) cout << "|";
        }
        cout << endl;
        break;
    case 9:
        d = strtod(sz, nullptr);
        pll = reinterpret_cast < unsigned long long * > ( & d);
        ll = 1;
        ll <<= sizeof(long long) * 8 - 1;
        for (n = sizeof(double) * 8 - 1; n >= 0; ll >>= 1, n--) {
            if (ll & * pll) cout << "1";
            else cout << "0";
            if (n % 63 == 0 || n % 52 == 0) cout << "|";
        }
        cout << endl;
        break;
    }
}
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32
}