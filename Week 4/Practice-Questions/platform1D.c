#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
    int i,b[50],size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d",&b[i]);
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}
int platform1D(int ar[], int size)
{
    int i, j, found, max, tempNumFreq[50][2], tempArraySize = 1;

    if (size > 50 || size < 0) {
        return -1;
    }

    // store the num and frequency into tempNumFreq
    for (i = 0; i < size; i++) {
        if (i == 0) {
            tempNumFreq[0][0] = ar[0];
            tempNumFreq[0][1] = 1;
        }
        else {
            found = 0;
            // go through the tempNumFreq array and check whether number exist inside array
            for (j = 0; j < tempArraySize; j++) {
                if (ar[i] == tempNumFreq[j][0]) {
                    // if exist, inc freq
                    tempNumFreq[j][1]++;
                    found = 1;
                }
            }
            // if does not exist, add new number
            if (!found) {
                tempNumFreq[tempArraySize][0] = ar[i];
                tempNumFreq[tempArraySize][1] = 1;
                tempArraySize++;
            }
        }
    }

    // go through the frequency and find max frequency
    max = tempNumFreq[0][0];
    for (i = 0; i < tempArraySize; i++) {
        if(tempNumFreq[i][1] > max) {
            max = tempNumFreq[i][1];
        }
    }
    return max;
}
