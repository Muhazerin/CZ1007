/*#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}
int extOddDigits1(int num)
{
    int oddSum = 0, pow = 1;
    if (num < 1) {
        return -1;
    }
    while (num > 0) {
        if (num % 2 != 0) {
            oddSum += (num % 10) * pow;
            pow *= 10;
        }
        num /= 10;
    }
    if (oddSum == 0) {
        oddSum = -1;
    }
    return oddSum;
}
void extOddDigits2(int num, int *result)
{
    int pow = 1;
    *result = 0;
    if (num < 1) {
        *result = -1;
        return;
    }
    while (num > 0) {
        if (num % 2 != 0) {
            *result += (num % 10) * pow;
            pow *= 10;
        }
        num /= 10;
    }
    if (*result == 0) {
        *result = -1;
    }
}
*/
