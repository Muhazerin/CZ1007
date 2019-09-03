/*#include <stdio.h>
void readInput(int *id, int *noOfHours, int *payRate);
void printOutputs(int id, double grossPay);
double computeSalary1(int noOfHours, int payRate);
void computeSalary2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int id = -1, noOfHours, payRate;
    double grossPay;

    readInput(&id, &noOfHours, &payRate);
    while (id != -1) {
        printf("computeSalary1(): ");
        grossPay = computeSalary1(noOfHours, payRate);
        printOutputs(id, grossPay);
        printf("computeSalary2(): ");
        computeSalary2(noOfHours, payRate, &grossPay);
        printOutputs(id, grossPay);
        readInput(&id, &noOfHours, &payRate);
    }
    return 0;
}
void readInput(int *id, int *noOfHours, int *payRate)
{
    puts("Enter ID (-1 to end):");
    scanf("%d", id);
    if (*id == -1) {
        return;
    }
    do {
        puts("Enter number of hours: ");
        scanf("%d", noOfHours);
        if (*noOfHours < 1) {
            puts("Please enter a number more than 0");
        }
    }
    while (*noOfHours < 1);
    do {
        puts("Enter hourly pay rate: ");
        scanf("%d", payRate);
        if (*payRate < 1) {
            puts("Please enter a number more than 0");
        }
    }
    while (*payRate < 1);
}
void printOutputs(int id, double grossPay)
{
    printf("ID %d grossPay %.2lf\n", id, grossPay);
}
double computeSalary1(int noOfHours, int payRate)
{
    double sal;
    (noOfHours > 160) ? (sal = (double)160 * (double)payRate  + ((double)noOfHours - 160) * (1.5 * (double)payRate)) : (sal = (double)noOfHours * (double)payRate);
    return sal;
}
void computeSalary2(int noOfHours, int payRate, double *grossPay)
{
    *grossPay = 0;
    (noOfHours > 160) ? (*grossPay = (double)160 * (double)payRate  + ((double)noOfHours - 160) * (1.5 * (double)payRate)) : (*grossPay = (double)noOfHours * (double)payRate);
}
*/
