#include <stdio.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
    char a[80],b[80];
    char ch;

    printf("Enter a string: \n");
    gets(a);
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
    int i;

    i = 0;
    while(*str1 != '\0') {
        i++;
        *(str2++) = *(str1++);
        if (i == 3) {
            i = 0;
            *(str2++) = ch;
        }
    }
    *str2 = '\0';
}
