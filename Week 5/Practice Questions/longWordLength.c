#include <stdio.h>
int longWordLength(char *s);
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}
int longWordLength(char *s)
{
    int oldResult, newResult;

    oldResult = newResult = 0;
    while (*s != '\0') {
        if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) {
            newResult++;
        }
        else {
            if(newResult > oldResult) {
                oldResult = newResult;
            }
            newResult = 0;
        }
        s++;
    }
    return oldResult;
}
