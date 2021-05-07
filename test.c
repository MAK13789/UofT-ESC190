#include <stdio.h>
int main()
{
    int temp[] = {1,2,3,4,5};
    for (int i = 0; i <= 4; i++)
    {
        printf("%d\n", *(temp+i));
    }
}