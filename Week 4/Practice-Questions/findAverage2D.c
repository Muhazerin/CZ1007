#include <stdio.h>
void findAverage2D(float matrix[4][4]);
int main()
{
    float ar[4][4];
    int i,j;

    printf("Enter data: \n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            scanf("%f", &ar[i][j]);
    }
    findAverage2D(ar);
    printf("findAverage2D(): :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%.2f ", ar[i][j]);
        printf("\n");
    }
    return 0;
}
void findAverage2D(float matrix[4][4])
{
    int row, col;
    float sum;

    for(row = 0; row < 4; row++) {
        sum = 0;
        for(col = 0; col < 3; col++) {
            sum += matrix[row][col];
        }
        matrix[row][3] = sum / 3;
    }
}
