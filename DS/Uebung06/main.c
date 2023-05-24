#include <stdio.h>

int main() {

    int a, b;
    char op, choice;

    do {
        puts("Enter 2 numbers from [1, 9]:");
        scanf("%d %d", & a, & b);
        getchar();
        puts("Enter +, -, * or /: ");
        scanf("%c", & op);
        getchar();

        switch (op) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
        default:
            puts("wrong entry\n");
            break;
        }

        printf("\nFurther calculation? y/n: ");
        scanf("%c", & choice);
        putchar(getchar());
    } while (choice == 'y');
    
    return 0;
}