#include <stdio.h>
int rAllOddDigits1(int num);
void rAllOddDigits2(int num, int *result);
int main()
{
    int number, result=-1;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
    rAllOddDigits2(number, &result);
    printf("rAllOddDigits2(): %d\n", result);
    return 0;
}
int rAllOddDigits1(int num)
{
    if (num < 10){
        if (num % 2 == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        if (num % 2 == 0) {
            return 0 * rAllOddDigits1(num / 10);
        }
        else {
            return 1 * rAllOddDigits1(num / 10);
        }
    }
}
void rAllOddDigits2(int num, int *result)
{
    if (num < 10) {
        if (num % 2 == 0) {
            *result = 0;
        }
        else {
            *result = 1;
        }
    }
    else {
        if (num % 2 == 0) {
            rAllOddDigits2(num / 10, result);
            *result *= 0;
        }
        else {
            rAllOddDigits2(num / 10, result);
            *result *= 1;
        }
    }
}
