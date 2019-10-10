#include <stdio.h>
typedef struct {
    char source;
    char code;
} Rule;
void createTable(Rule *table, int *size);
void printTable(Rule *table, int size);
void encodeChar(Rule *table, char *s, char *t);
int main()
{
    char s[80],t[80], dummychar;
    int size, choice;
    Rule table[100];

    printf("Select one of the following options:\n");
    printf("1: createTable()\n");
    printf("2: printTable()\n");
    printf("3: encodeChar()\n");
    printf("4: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("createTable(): \n");
                createTable(table, &size);
                break;
            case 2:
                printf("printTable(): \n");
                printTable(table, size);
                break;
            case 3:
                scanf("%c",&dummychar);
                printf("Source string: \n");
                gets(s);
                encodeChar(table,s,t);
                printf("Encoded string: %s\n", t);
                break;
            default:
                break;
        }
    } while (choice < 4);
    return 0;
}
void printTable(Rule *table, int size)
{
int i;
    for (i=0; i<size; i++)
    {
        printf("%d: %c->%c\n", i+1, table->source, table->code);
        table++;
    }
}
void createTable(Rule *table, int *size)
{
    int i;

    puts("Enter number of rules:");
    scanf("%d", size);
    for(i = 0; i < *size; i++) {
        printf("Enter rule %d:\n", i+1);
        puts("Enter source character:");
        scanf("\n%c", &table[i].source);
        puts("Enter code character:");
        scanf("\n%c", &table[i].code);
    }
    table[*size].source = '\0';
    table[*size].code = '\0';
}
void encodeChar(Rule *table, char *s, char *t)
{
    int i, found, len = 0;

    while(table[len++].source != '\0') {
        ;
    }
    len--;

    while(*s != '\0') {
        found = 0;
        for (i = 0; i < len; i++) {
            if(*s == table[i].source) {
                found = 1;
                *t = table[i].code;
                break;
            }
        }
        if(!found) {
            *t = *s;
        }
        t++;
        s++;
    }
    *t = '\0';
}
