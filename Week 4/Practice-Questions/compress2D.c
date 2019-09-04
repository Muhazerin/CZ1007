#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;

    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    int tempArray[SIZE][SIZE], row, col, temp10Freq[SIZE][2], tempDigit, tempFreqIndex, tempArrayRow, tempArrayCol[rowSize], i;

    if (rowSize != colSize || rowSize < 1) {
        return;
    }

    // clear temp10Freq array by setting all -1
    for(row = 0; row < SIZE; row++) {
        temp10Freq[row][0] = -1;
        temp10Freq[row][1] = -1;
    }

    tempArrayRow = 0;
    for(row = 0; row < rowSize; row++) {
        tempDigit = -1;
        tempFreqIndex = 0;
        for(col = 0; col < colSize; col++) {
            if (tempDigit == -1) {
                tempDigit = data[row][col];
                temp10Freq[tempFreqIndex][0] = tempDigit;
                temp10Freq[tempFreqIndex][1] = 1;
                continue;
            }
            if (tempDigit != data[row][col]) {
                tempFreqIndex++;
                tempDigit = data[row][col];
                temp10Freq[tempFreqIndex][0] = tempDigit;
                temp10Freq[tempFreqIndex][1] = 1;
            }
            else {
                temp10Freq[tempFreqIndex][1]++;
            }
        }

        // need to save the frequency into a new tempArray row
        col = 0;
        for(i = 0; i <= tempFreqIndex; i++) {
            tempArray[tempArrayRow][col++] = temp10Freq[i][0];
            tempArray[tempArrayRow][col++] = temp10Freq[i][1];
        }
        tempArrayCol[tempArrayRow] = col;
        tempArrayRow++;

        // need to clear temp10Freq array
        for(i = 0; i < SIZE; i++) {
            temp10Freq[i][0] = -1;
            temp10Freq[i][1] = -1;
        }
    }

    for (row = 0; row < tempArrayRow; row++) {
        for (col = 0; col < tempArrayCol[row]; col++) {
            printf("%d ", tempArray[row][col]);
        }
        printf("\n");
    }
}
