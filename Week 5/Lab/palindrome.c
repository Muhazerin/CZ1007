#include <stdio.h>
#define INIT_VALUE -1000
int palindrome(char *str);
int main()
{
    char str[80];
    int result = INIT_VALUE;
    printf("Enter a string: \n");

    gets(str);
    result = palindrome(str);
    if (result == 1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
    else
        printf("An error\n");
    return 0;
}
int palindrome(char *str)
{
    int len, i, result;
    char *strPtr = str;

    len = 0;
    while (*(strPtr++) != '\0') {
        len++;
    }
    strPtr--;
    strPtr--;

    len /= 2;
    result = 1;
    for (i = 0; i < len; i++) {
        if(*(str++) != *(strPtr--)) {
            result = 0;
            break;
        }
    }
    return result;
}
