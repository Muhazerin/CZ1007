#include <stdio.h>
int countSubstring(char str[], char substr[]);
int main()
{
    char str[80],substr[80];

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    printf("countSubstring(): %d\n", countSubstring(str, substr));
    return 0;
}
int countSubstring(char str[], char substr[])
{
    char *strTemp, *substrTemp;
    int substrLen, i, found, noOfSubStr;

    strTemp = str;
    substrTemp = substr;
    substrLen = 0;
    while(*(substrTemp++) != '\0') {
        substrLen++;
    }
    substrTemp = substr;

    found = noOfSubStr = 0;
    while(*strTemp != '\0') {
        if(*strTemp == *substrTemp) {
            found = 1;
            for(i = 0; i < substrLen; i++) {
                if(*(strTemp+i) != *(substr+i)) {
                    found = 0;
                }
            }
            if(found) {
                found = 0;
                noOfSubStr++;
            }
        }

        strTemp++;
    }
    return noOfSubStr;
}
