#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 21 // longest possible input including '\0'

void dec2bin(int, char[]);
void clearScreen();

int main() {
    int choice;
    char sz[LEN];
    while (1) {
        clearScreen();
        puts("Datatypes\n---------\n");
        puts(" 0 - unsigned char");
        puts(" 1 - signed char");
        puts(" 2 - unsigned int");
        puts(" 3 - signed int");
        puts(" 4 - unsigned long");
        puts(" 5 - signed long");
        puts(" 6 - unsigned long long");
        puts(" 7 - signed long long\n");
        puts(" 8 - float");
        puts(" 9 - double\n");
        puts("10 - end\n");
        printf("Your choice: ");
        scanf("%i", & choice);
        switch (choice) {
        case 0:
            printf("\nunsigned char number: ");
            break;
        case 1:
            printf("\nsigned char number: ");
            break;
        case 2:
            printf("\nunsigned int: ");
            break;
        case 3:
            printf("\nsigned int: ");
            break;
        case 4:
            printf("\nunsigned long: ");
            break;
        case 5:
            printf("\nsigned long: ");
            break;
        case 6:
            printf("\nunsigned long long: ");
            break;
        case 7:
            printf("\nsigned long long: ");
            break;
        case 8:
            printf("\nfloat: ");
            break;
        case 9:
            printf("\ndouble: ");
            break;
        case 10:
            printf("\nProgram terminated!\n");
            return 1;
        default:
            puts("\nWrong entry - program terminated!\n");
            return 1;
        }
        scanf("%s", sz);
        dec2bin(choice, sz);
        printf("\nPlease press <RETURN>");
        getchar();
        getchar();
    }
    return 0;
}

void dec2bin(int nChoice, char sz[]) {
    unsigned char uc, c = 1;
    c <<= sizeof(char) * 8 - 1;
    unsigned int ui, i = 1, * pi = NULL;
    i <<= sizeof(int) * 8 - 1; // Was bewirkt diese Zeile? // 1
    unsigned long ul, l = 1;
    l <<= sizeof(long) * 8 - 1;
    unsigned long long ull, ll = 1, * pll = NULL;
    ll <<= sizeof(long long) * 8 - 1;
    float f;
    double d;
    int n; // Wofür wird n benötigt? // 2
    printf("\nbinary: |");
    switch (nChoice) {
    case 0:
    case 1:
        uc = strtoul(sz, NULL, 10);
        for (n = sizeof(char) * 8 - 1; n >= 0; c >>= 1, n--) {
            if (c & uc) printf("1");
            else printf("0");
            if (n % 8 == 0) printf("|");
        }
        puts("");
        break;
    case 2:
    case 3: // Warum kann man die Fälle 2 und 3 zusammenfassen? // 3
        ui = strtoul(sz, NULL, 10); // Was bewirkt dieser Befehl? // 4
        for (n = sizeof(int) * 8 - 1; n >= 0; i >>= 1, n--) {
            if (i & ui) printf("1");
            else printf("0");
            if (n % 8 == 0) printf("|");
        } // Beschreiben Sie im Detail, was genau diese Schleife tut. // 5
        puts("");
        break;
    case 4:
    case 5:
        ul = strtoul(sz, NULL, 10);
        for (n = sizeof(long) * 8 - 1; n >= 0; l >>= 1, n--) {
            if (l & ul) printf("1");
            else printf("0");
            if (n % 8 == 0) printf("|");
        }
        puts("");
        break;
    case 6:
    case 7:
        ull = strtoull(sz, NULL, 10); // Was bewirkt dieser Befehl? // 6
        for (n = sizeof(long long) * 8 - 1; n >= 0; ll >>= 1, n--) {
            if (ll & ull) printf("1");
            else printf("0");
            if (n % 8 == 0) printf("|");
        }
        puts("");
        break;
    case 8:
        f = strtof(sz, NULL);
        pi = (unsigned int * )( & f); // Welchen Sinn hat dieser Befehl? // 7
        i = 1; // Warum wird hier i statt l genutzt? // 8
        i <<= sizeof(int) * 8 - 1;
        for (n = sizeof(float) * 8 - 1; n >= 0; i >>= 1, n--) {
            if (i & * pi) printf("1");
            else printf("0");
            if (n % 31 == 0 || n % 23 == 0) printf("|");
        } // Beschreiben Sie im Detail, was diese Schleife tut. // 9
        puts("");
        break;
    case 9:
        d = strtod(sz, NULL);
        pll = (unsigned long long * )( & d);
        ll = 1;
        ll <<= sizeof(long long) * 8 - 1;
        for (n = sizeof(double) * 8 - 1; n >= 0; ll >>= 1, n--) {
            if (ll & * pll) printf("1");
            else printf("0");
            if (n % 63 == 0 || n % 52 == 0) printf("|");
        }
        puts("");
        break;
    }
}

void clearScreen() { // Wofür wird diese Funktion benötigt? // 10
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}