/*#include <stdio.h>
int main()
{
    int total, count, lines, input;
    double average;
    int i;
    printf("Enter number of lines: \n");
    scanf("%d", &lines);

    for (i = 0; i < lines; i++) {
        count = 0, input = 0, total = 0;
        printf("Enter line %d (end with -1):\n", i+1);
        do {
            scanf("%d", &input);
            total += input;
            count++;
        } while (input > 0);
        total++;
        count--;
        average = (double)total / count;
        printf("Average = %.2lf\n", average);
    }

    return 0;
}
*/
