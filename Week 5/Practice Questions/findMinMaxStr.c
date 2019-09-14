#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int
size);
int main()
{
    char word[SIZE][40];
    char first[40], last[40];
    int i, size;

    printf("Enter size: \n");
    scanf("%d", &size);
    printf("Enter %d words: \n", size);
    for (i=0; i<size; i++)
        scanf("%s", word[i]);
    findMinMaxStr(word, first, last, size);
    printf("First word = %s, Last word = %s\n", first, last);
    return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size)
{
    int i = 0;
    char *tempFirst, *tempLast;
    tempFirst = tempLast = word[0];

    while (i < size) {
        if(strcmp(word[i], tempFirst) < 0) {
            tempFirst = word[i];
        }
        if(strcmp(word[i], tempLast) > 0) {
            tempLast = word[i];
        }
        i++;
    }
    strcpy(first, tempFirst);
    strcpy(last, tempLast);
}
