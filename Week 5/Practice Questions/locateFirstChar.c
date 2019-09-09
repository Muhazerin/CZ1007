#include <stdio.h>
int locateFirstChar(char *str, char ch);
int main()
{
    char str[40], ch;

    printf("Enter a string: \n");
    gets(str);
    printf("Enter the target character: \n");
    scanf("%c", &ch);
    printf("locateFirstChar(): %d\n", locateFirstChar(str, ch));
    return 0;
}
int locateFirstChar(char *str, char ch)
{
    int i, found;

    i = found = 0;
    while(*str != '\0') {
        if(ch == *str) {
            found = 1;
            break;
        }

        i++;
        str++;
    }
    if(!found) {
        i = -1;
    }
    return i;
}
