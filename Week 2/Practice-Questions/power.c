#include <stdio.h>
int main()
{
    double current, resistance, power;

    puts("Enter the current:");
    scanf("%lf", &current);
    puts("Enter the resistance:");
    scanf("%lf", &resistance);

    power = current * current * resistance;
    printf("The power loss: %.2lf", power);

    return 0;
}
