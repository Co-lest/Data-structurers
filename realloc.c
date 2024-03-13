#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(sizeof(int)*4);
    if (list == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < 4; i++)
    {
        *(&list[i]) = i;
    }
    //free(list);
    
    int *temp = realloc(list, sizeof(int)*5);
    if (temp == NULL)
    {
        return 1;
    }
    list = temp;
    *(temp + 4) = 5;
    free(list);
    free(temp);

    return 0;
}