#include <stdio.h>
#include <stdlib.h>

int check(int i, int *a);

int main()
{
    int a[5];

    for (int i = 0; i <= 4; i += 0)
    {
        printf("Enter unique integer number %d: ", i + 1);
        scanf("%d", &a[i]);
        if (check(i, a))
        {
            i++;
        }
    }
    int *ptr = a;
    for (int j = 0; j < 5; j++)
    {
        printf("%d\n", *(ptr + j)); // a[j]
    }
    return 0;
}

int check(int i, int *a)
{
    int *ptr2 = a;
    if (*(&a[i]) > 10) // a[i] > 10
    {
        printf("Enter a valid unique number, should be less than ten\n");
        return 0;
    }
    else
    {
        for (int y = 0; y < 5; y++)
        {
            if (i != y && *(&ptr2[i]) == *(&ptr2[y])) // a[i] == a[y]
            {
                printf("Enter a valid unique number, should not repeat\n");
                return 0;
            }
        }
        return 1;
    }
}