#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s);
void decipher(char *s);
int main()
{
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    printf("To cipher: %s -> ", str);
    cipher(str);
    printf("%s\n", str);
    printf("To decipher: %s -> ", str);
    decipher(str);
    printf("%s\n", str);
    return 0;
}
void cipher(char *s)
{
    char *temp = s;

    while(*temp != '\0') {
        if(isalpha(*temp)) {
            if(*temp == 90) {
                *temp = 65;
            }
            else if (*temp == 122) {
                *temp = 97;
            }
            else {
                (*temp)++;
            }
        }

        temp++;
    }
}
void decipher(char *s)
{
    char *temp = s;

    while(*temp != '\0') {
        if(isalpha(*temp)) {
            if(*temp == 65) {
                *temp = 90;
            }
            else if (*temp == 97) {
                *temp = 122;
            }
            else {
                (*temp)--;
            }
        }

        temp++;
    }
}

