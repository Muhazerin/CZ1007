#include <stdio.h>
#include <string.h>
struct student{
    char name[20]; /* student name */
    double testScore; /* test score */
    double examScore; /* exam score */
    double total; /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
    printf("average(): %.2f\n", average());
    return 0;
}
double average()
{
    char temp[1];
    double sum;
    int i;
    struct student studentRec[50];

    sum = i = 0;
    puts("Enter student name: ");
    gets(studentRec[0].name);
    while (strcmp(studentRec[i].name, "END") != 0 && i < 50) {
        puts("Enter test score: ");
        scanf("%lf", &studentRec[i].testScore);
        puts("Enter exam score: ");
        scanf("%lf", &studentRec[i].examScore);
        studentRec[i].total = (studentRec[i].testScore + studentRec[i].examScore) / 2;
        sum += studentRec[i].total;
        printf("Student %s total = %.2lf\n", studentRec[i].name, studentRec[i].total);

        i++;
        puts("Enter student name: ");
        gets(temp); // this is used to clear the \n in the buffer
        gets(studentRec[i].name);
    }

    if (i == 0) {
        return 0;
    }
    else {
        return sum / i;
    }
}
