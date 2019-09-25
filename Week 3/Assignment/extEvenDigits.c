#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num)
{
    int digit, temp, i, count = 0, result = -1;
    if (num < 0) {
        return result;
    }
    while (num > 0) {
        digit = num % 10;
        temp = 1;
        if ((digit % 2) == 0){
            if (result == -1) {
                result = digit;
                count++;
            }
            else {
                for(i = 0; i < count; i++) {
                    temp = temp * 10;
                }
                result = (digit * temp) + result;
                count++;
            }
        }
        num /= 10;
    }
    return result;
}
void extEvenDigits2(int num, int *result)
{
    int digit, temp, i, count = 0;
    *result = -1;
    if (num < 0) {
        return;
    }
    while (num > 0) {
        digit = num % 10;
        temp = 1;
        if ((digit % 2) == 0){
            if (*result == -1) {
                *result = digit;
                count++;
            }
            else {
                for (i = 0; i < count; i++) {
                    temp = temp * 10;
                }
                *result = (digit * temp) + *result;
                count++;
            }
        }
        num /= 10;
    }
}
