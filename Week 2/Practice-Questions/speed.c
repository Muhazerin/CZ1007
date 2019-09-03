#include <stdio.h>
int main()
{
    int distance, time;
    double speed;

    puts("Enter distance (in km):");
    scanf("%d", &distance);
    puts("Enter time (in sec):");
    scanf("%d", &time);

    speed =  (double)distance / time;
    printf("The speed is %.2lf km/sec\n", speed);

    return 0;
}
