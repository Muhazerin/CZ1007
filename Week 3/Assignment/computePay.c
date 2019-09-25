#include <stdio.h>
double computePay1(int noOfHours, int payRate);
void computePay2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int noOfHours, payRate;
    double grossPay;

    printf("Enter number of hours: \n");
    scanf("%d", &noOfHours);
    printf("Enter hourly pay rate: \n");
    scanf("%d", &payRate);
    printf("computePay1(): %.2f\n", computePay1(noOfHours, payRate));
    computePay2(noOfHours, payRate, &grossPay);
    printf("computePay2(): %.2f\n", grossPay);
    return 0;
}
double computePay1(int noOfHours, int payRate)
{
    if (noOfHours < 0 || payRate < 0) {
        return 0;
    }
    if (noOfHours > 160) {
        noOfHours -= 160;
        return ((double)noOfHours * (double)payRate * 1.5) + (160 * payRate);
    }
    else {
        return (double)noOfHours * (double)payRate;
    }
}
void computePay2(int noOfHours, int payRate, double *grossPay)
{
    if (noOfHours < 0 || payRate < 0) {
        grossPay = 0;
        return;
    }
    if (noOfHours > 160) {
        noOfHours -= 160;
        *grossPay = ((double)noOfHours * (double)payRate * 1.5) + (160 * payRate);
    }
    else {
        *grossPay = (double)noOfHours * (double)payRate;
    }
}
