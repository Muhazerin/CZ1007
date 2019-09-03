/*#include <stdio.h>
int main()
{
    int hours;
    float tax, grossPay, netPay;

    printf("Enter hours of work: \n");
    scanf("%d", &hours);

    if(hours > 40) {
        hours = hours - 40;
        grossPay = 40 * 6;
        grossPay += hours * 9;
    }
    else {
        grossPay = hours * 6;
    }

    if(grossPay > 1500) {
        tax = (0.1 * 1000) + (0.2 * 500);
        tax += 0.3 * (grossPay - 1500);
    }
    else if(grossPay > 1000) {
        tax = 0.1 * 1000;
        tax += 0.2 * (grossPay - 1000);
    }
    else {
        tax = 0.1 * grossPay;
    }
    netPay = grossPay - tax;

    printf("Gross pay = %.2f\n", grossPay);
    printf("Tax = %.2f\n", tax);
    printf("Net pay = %.2f\n", netPay);
    return 0;
}
*/
