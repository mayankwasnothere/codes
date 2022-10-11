#include <stdio.h>
#include <stdlib.h>

int swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    srand(time(0));

    int a, b, c;
    a = rand() / 1e5;
    b = rand() / 1e5;
    c = rand() / 1e5;

    printf("Intial Values: %d %d %d\n", a, b, c);

    swap(&a, &b);
    swap(&b, &c);
    printf("Swapped Values: %d %d %d\n", a, b, c);
}