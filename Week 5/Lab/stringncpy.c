#include <stdio.h>
char *stringncpy(char *s1, char *s2, int n);
int main()
{
    char sourceStr[40], targetStr[40], *target;
    int length;
    printf("Enter the string: \n");
    gets(sourceStr);
    printf("Enter the number of characters: \n");
    scanf("%d", &length);
    target = stringncpy(targetStr, sourceStr, length);
    printf("stringncpy(): %s\n", target);
    return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
    int i, strTooShort;

    strTooShort = 0;
    for (i = 0; i < n ; i++) {
        if(*(s2+i) == '\0') {
            strTooShort = 1;
            break;
        }
        *(s1+i) = *(s2+i);
    }
    if(strTooShort) {
        while (i < n) {
            *(s1+i) = '\0';
            i++;
        }
    }

    *(s1+i) = '\0';
    return s1;
}
