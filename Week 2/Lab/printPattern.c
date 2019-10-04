#include <stdio.h>
int main()
{
    int row, col, height;
    int num = 0;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern: \n");
    if (height > 0 && height < 11) {
        num = 1;
        for (row = 1; row <= height; row++) {
            num %= 3;
            if (num == 0) {
                num = 3;
            }
            for (col = 0; col < row; col++) {
                printf("%d", num);
            }
            puts("");
            num++;
        }
    }
    else {
        puts("Invalid height");
    }
    return 0;
}
