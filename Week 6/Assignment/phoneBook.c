#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[20];
    char telno[20];
} PhoneBk;
void printPB(PhoneBk *p, int size);
int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);
int main()
{
    PhoneBk s[MAX];
    char t[20];
    int size=0, choice, dummychar;

    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: printPB()\n");
    printf("4: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%c", &dummychar);
                size = readin(s);
                break;
            case 2:
                scanf("%c", &dummychar);
                printf("Enter search name: \n");
                gets(t);
                search(s,size,t);
                break;
            case 3:
                printPB(s, size);
                break;
        }
    } while (choice < 4);
    return 0;
}
void printPB(PhoneBk *p, int size)
{
    int i;

    if(size == 0) {
        puts("Empty phonebook");
    }
    else {
        puts("The phonebook list:");
        for(i = 0; i < size; i++) {
            printf("Name: %s\nTelno: %s\n", p[i].name, p[i].telno);
        }
    }
}
int readin(PhoneBk *p)
{
    int i = 0;
    puts("Enter name:");
    gets(p[i].name);
    while (strcmp(p[i].name, "#") != 0) {
        puts("Enter Tel no:");
        scanf("\n");
        gets(p[i].telno);
        i++;
        if(i >= MAX) {
            puts("Phonebook is full");
            break;
        }
        puts("Enter name:");
        scanf("\n");
        gets(p[i].name);
    }
    return i;
}
void search(PhoneBk *p, int size, char *target)
{
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(target, p[i].name) == 0) {
            printf("Name: %s, Tel = %s\n", p[i].name, p[i].telno);
            return;
        }
    }
    puts("Name not found!");
}
