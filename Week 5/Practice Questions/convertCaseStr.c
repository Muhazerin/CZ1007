#include <stdio.h>
#include <ctype.h>
void convertCaseStr(char *str);
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    convertCaseStr(str);
    printf("convertCaseStr(): %s\n", str);
    return 0;
}
void convertCaseStr(char *str)
{
    char *strPtr = str;
    while (*strPtr != '\0') {
        if(isalpha(*strPtr)) {
            if(islower(*strPtr)) {
                *strPtr = toupper(*strPtr);
            }
            else {
                *strPtr = tolower(*strPtr);
            }
        }
        strPtr++;
    }
}
