//use malloc to avoid two pointers to point to the same value

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *name = "mark Tom";
    int j = strlen(name);
    char *ptr = malloc(j + 1); //malloc returns the first adress of the memory it allocates   plus one because of nul terminator

    if(ptr ==  NULL)
    {
        return 1;
    }

    strcpy(name, ptr);

    if(j > 0)
    {
        *(ptr) = toupper(*(ptr)); //same as *(ptr+0);
    }
    
    printf("Before: ");
    for (int i = 0; i != \0; i++)
    {
        printf("%s", *(&name[i]));
    }
    printf("\n");
    printf("After: ");
    for (int i = 0; i != \0; i++)
    {
        printf("%s", *(ptr + i));
    }
    free(ptr);
    return 0;
}