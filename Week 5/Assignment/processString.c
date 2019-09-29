#include <stdio.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
    char str[50];
    int totVowels, totDigits;

    printf("Enter the string: \n");
    gets(str);
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    *totVowels = 0;
    *totDigits = 0;

    while (*str != '\0') {
        if(*str == 'a' || *str == 'A' || *str == 'e' || *str == 'E' || *str == 'i' || *str == 'I' || *str == 'o' || *str == 'O' || *str == 'u' || *str == 'U') {
            (*totVowels)++;
        }
        if(*str >= '0' && *str <= '9') {
            (*totDigits)++;
        }
        str++;
    }
}

