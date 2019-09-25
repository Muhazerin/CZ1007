#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50],i,size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d",ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++)
        printf("%d ",*(ar+i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    int i, temp, min, max, minIndex, maxIndex;

    if (size < 1) {
        return;
    }

    min = max = ar[0];
    minIndex = maxIndex = 0;
    for (i = 1; i < size; i++) {
        if (ar[i] >= max) {
            max = ar[i];
            maxIndex = i;
        }
        if (ar[i] <= min) {
            min = ar[i];
            minIndex = i;
        }
    }


    // do the swapping
    temp = ar[maxIndex];
    ar[maxIndex] = ar[minIndex];
    ar[minIndex] = temp;
}
