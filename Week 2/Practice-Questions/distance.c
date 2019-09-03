#include <stdio.h>
#include <math.h>
int main()
{
    double x1, x2, y1, y2, distance, xDiff, yDiff;

    puts("Enter first point x1 y1:");
    scanf("%lf %lf", &x1, &y1);
    puts("Enter second point x2 y2:");
    scanf("%lf %lf", &x2, &y2);

    xDiff = x1 - x2;
    yDiff = y1 - y2;
    distance = sqrt(pow(xDiff,2) + pow(yDiff, 2));

    //printf("xDiff^2: %.2lf, yDiff^2: %.2lf\n", pow(xDiff,2), pow(yDiff, 2));
    printf("The distance is %.2lf\n", distance);

    return 0;
}
