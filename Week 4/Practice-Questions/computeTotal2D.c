#include <stdio.h>
#define SIZE 4
void computeTotal2D(int matrix[SIZE][SIZE]);
int main()
{
    int a[SIZE][SIZE];
    int i,j;

    printf("Enter the matrix data (%dx%d): \n", SIZE, SIZE);
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            scanf("%d", &a[i][j]);
    printf("computeTotal2D(): \n");
    computeTotal2D(a);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%d ", a[i][j]);
    printf("\n");
}
return 0;
}
void computeTotal2D(int matrix[SIZE][SIZE])
{
    int row, col;
    float sum;

    for(row = 0; row < SIZE; row++) {
        sum = 0;
        for(col = 0; col < SIZE - 1; col++) {
            sum += matrix[row][col];
        }
        matrix[row][3] = sum;
    }
}
