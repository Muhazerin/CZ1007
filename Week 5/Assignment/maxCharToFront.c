#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}
void maxCharToFront(char *str)
{
    int index, i;
    char max;
    char *temp = str;

    i = index = 0;
    max = 'A';
    while (*temp != '\0') {
        if(*temp > max) {
            index = i;
            max = *temp;
        }
        i++;
        temp++;
    }
    temp = str;
    for(i = index; i > 0; i--) {
        *(str+i) = *(str+i-1);
    }
    *str = max;
}

