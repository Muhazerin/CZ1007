include <stdio.h>
int main()
{
    int list, coe = 0, cat;
    double discounted, luxury = 0, gst, total;

    printf("Please enter the list price: \n");
    scanf("%d", &list);
    printf("Please enter the category: \n");
    scanf("%d", &cat);

    if (cat == 1)
        coe = 70000;
    else if (cat == 2)
        coe = 80000;
    else if (cat == 3)
        coe = 23000;
    else
        coe = 600;

    discounted = 0.9 * list;
    if (discounted > 100000) {
        luxury = 0.1 * discounted;
    }
    gst = 0.03 * discounted;
    total = discounted + luxury + gst + coe;

    printf("Total price is $%.2lf\n", total);
    return 0;
}
