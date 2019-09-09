#include <stdio.h>
#define INIT_VALUE 999
int findSubstring(char *str, char *substr);
int main()
{
    char str[40], substr[40];
    int result = INIT_VALUE;

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    result = findSubstring(str, substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if ( result == 0)
        printf("findSubstring(): Not a substring\n");
    else
        printf("findSubstring(): An error\n");
    return 0;
}
int findSubstring(char *str, char *substr)
{
    int i, len, result, found;

    len = 0;
    while(*(substr+len) != '\0') {
        len++;
    }

    result = 0;
    found = 0;
    while (*str != '\0') {
        if(*str == *substr) {
            found = 1;
            for(i = 0; i < len; i++) {
                if(*(str+i) != *(substr+i)) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                result = 1;
                break;
            }
        }

        str++;
    }
    return result;
}
