#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main()
{
    int x = 1;
    int y = 2;
    printf("The value of x: %i, y: %i", x, y);
    swap(&x, &y);
    printf("The value of x: %i, y: %i", x, y);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}