#include <stdio.h>
int digitValue1(int num, int k);
void digitValue2(int num, int k, int *result);
int main()
{
    int num, digit, result=-1;

    printf("Enter the number: \n");
    scanf("%d", &num);
    printf("Enter k position: \n");
    scanf("%d", &digit);
    printf("digitValue1(): %d\n", digitValue1(num, digit));
    digitValue2(num, digit, &result);
    printf("digitValue2(): %d\n", result);
    return 0;
}
int digitValue1(int num, int k)
{
    int i;
    if (num < 0 || k < 1) {
        return -1;
    }
    for (i = 0; i < k; i++) {
        if (num == 0) {
            break;
        }
        if (i == (k-1)) {
            return num % 10;
        }
        num /= 10;
    }
    return 0;
}
void digitValue2(int num, int k, int *result)
{
    int i;
    *result = 0;
    if (num < 0 || k < 1) {
        *result = -1;
        return;
    }
    for (i = 0; i < k; i++) {
        if (num == 0) {
            break;
        }
        if (i == (k-1)) {
            *result = num % 10;
        }
        num /= 10;
    }
}
