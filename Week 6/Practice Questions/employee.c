#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[40];
    char telno[40];
    int id;
    double salary;
} Employee;
int readin(Employee *p);
void printEmp(Employee *p, int size) ;
int search(Employee *p, int size, char *target);
int addEmployee(Employee *p, int size, char *target);
int main()
{
    Employee emp[MAX];
    char name[40];
    int size, choice, result;

    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: addEmployee()\n");
    printf("4: print()\n");
    printf("5: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size = readin(emp);
                break;
            case 2:
                printf("Enter search name: \n");
                scanf("\n");
                gets(name);
                result = search(emp,size,name);
                if (result != 1)
                    printf ("Name not found!\n");
                break;
            case 3:
                printf("Enter new name: \n");
                scanf("\n");
                gets(name);
                result = search(emp,size,name);
                if (result != 1)
                    size = addEmployee(emp, size, name);
                else
                    printf("The new name has already existed in the database\n");
                break;
            case 4:
                printEmp(emp, size);
                break;
            default:
                break;
        }
    } while (choice < 5);
    return 0;
}
int readin(Employee *p)
{
    int i = 0;

    puts("Enter name: ");
    scanf("\n");
    gets(p[i].name);
    while (strcmp(p[i].name, "#") != 0) {
        puts("Enter tel: ");
        scanf("\n");
        gets(p[i].telno);
        puts("Enter id: ");
        scanf("%d", &p[i].id);
        puts("Enter salary: ");
        scanf("%lf", &p[i].salary);
        i++;

        puts("Enter name: ");
        scanf("\n");
        gets(p[i].name);
    }
    return i;
}
void printEmp(Employee *p, int size)
{
    int i;

    puts("The current employee list:");
    for(i = 0; i< size; i++) {
        printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
    }
}
int search(Employee *p, int size, char *target)
{
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(target, p[i].name) == 0) {
            printf("Employee found at index location: %d\n", i);
            printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
            return 1;
        }
    }
    return 0;
}
int addEmployee(Employee *p, int size, char *target)
{
    if (size == MAX) {
        puts("Database is full");
        return size;
    }
    strcpy(p[size].name, target);
    puts("Enter tel: ");
    gets(p[size].telno);
    puts("Enter id: ");
    scanf("%d", &p[size].id);
    puts("Enter salary: ");
    scanf("%lf", &p[size].salary);
    printf("Added at position: %d\n", size);

    return ++size;
}
