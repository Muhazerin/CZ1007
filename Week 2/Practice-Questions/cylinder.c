#include <stdio.h>
#define PI 3.1416
int main()
{
    int h, r;
    double vol, area;

    puts("Enter the radius:");
    scanf("%d", &r);
    puts("Enter the height:");
    scanf("%d", &h);

    vol = PI * r * r * h;
    area = (2 * PI * r * h) + (2 * PI * r * r);

    printf("The volume is: %.2lf\n", vol);
    printf("The surface area is: %.2lf\n", area);

    return 0;
}
