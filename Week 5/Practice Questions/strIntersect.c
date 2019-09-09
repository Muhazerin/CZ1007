#include <stdio.h>
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
    char str1[50],str2[50],str3[50];

    printf("Enter str1: \n");
    scanf("%s",str1);
    printf("Enter str2: \n");
    scanf("%s",str2);
    strIntersect(str1, str2, str3);
    if (*str3 == '\0')
        printf("strIntersect(): null string\n");
    else
        printf("strIntersect(): %s\n", str3);
    return 0;
}
void strIntersect(char *str1, char *str2, char *str3)
{
    char *str2Temp;

    str2Temp = str2;
    *str3 = '\0';
    while(*str1 != '\0') {
        str2 = str2Temp;
        while (*str2 != '\0') {
            if(*str2 == *str1) {
                *(str3++) = *str2;
                break;
            }
            str2++;
        }
        str1++;
    }
    *str3 = '\0';
}
