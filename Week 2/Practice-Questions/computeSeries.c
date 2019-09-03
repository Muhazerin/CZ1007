/*#include <stdio.h>
int main()
{
    int n, denominator = 1;
    float x, result = 1.0, numerator = 1.0;
    printf("Enter x: \n");
    scanf("%f", &x);

    for (n = 1; n <= 10; n++) {
        numerator = 1.0;
        denominator = 1;
        for (int i = 1; i <= n; i++) {
            numerator *= x;
            denominator *= i;
        }
        result += numerator / denominator;
    }

    printf("Result = %.2f\n", result);
    return 0;
}
*/
