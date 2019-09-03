#include <stdio.h>
int main()
{
    int row, col, height;
    int num = 0;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern: \n");

    if (height < 1 || height > 10) {
        puts("Invalid height");
        return 1;
    }
    col = num = 1;
    for (row = 0; row < height; row++) {
        num = num % 3;
        if (num == 0) {
            num = 3;
        }
        for (int j = 0; j < col; j++) {
            printf("%d", num);
        }
        printf("\n");
        col++;
        num++;
    }

    return 0;
}
