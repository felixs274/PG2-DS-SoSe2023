#include <stdio.h>
void printReverse(char *word, int length)
{
    if (length == 0)
    {
        return;
    }
    else
    {
        printf("%c", word[length - 1]);
        printReverse(word, length - 1);
    }
}
int main()
{
    char word[] = "ABC";
    int length = 3;
    printReverse(word, length);
    puts("");
    return 0;
}