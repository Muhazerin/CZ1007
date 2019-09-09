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
    int i;
    char *firstTemp, *lastTemp;

    for(i = 0; i < size; i++) {
        if (i == 0) {
            firstTemp = lastTemp = word[i];
        }
        else {
            if(strcmp(word[i], firstTemp) < 1) {
                if(strcmp(firstTemp, lastTemp) > 1) {
                    lastTemp = firstTemp;
                }
                firstTemp = word[i];
            }
            else if (strcmp(word[i], lastTemp) > 1){
                lastTemp = word[i];
            }
        }
    }
    while(*lastTemp != '\0') {
        *(last++) = *(lastTemp++);
    }
    while(*firstTemp != '\0') {
        *(first++) = *(firstTemp++);
    }
    *first = '\0';
    *last = '\0';
}
