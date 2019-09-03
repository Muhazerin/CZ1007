#include <stdio.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
    printf("%d ",a[i]);
    return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
    int *arPtr = ar;
    int tempDigit, i, sum, tempNum, currentNum;
    if (num < 100 || num > 999) {
        return;
    }

    currentNum = tempNum = 100;
    while (currentNum <= num) {
        sum = 0;
        for (i = 0; i < 3; i++) {
            tempDigit = tempNum % 10;
            sum += tempDigit * tempDigit * tempDigit;
            tempNum /= 10;
        }

        if (currentNum == sum) {
            *arPtr = currentNum;
            arPtr++;
            (*size)++;
        }
        currentNum++;
        tempNum = currentNum;
    }
}
