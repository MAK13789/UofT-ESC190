#include <stdio.h>
#include <stdlib.h>
//Question 12 :
int convert (int x)
{
    return x + (-x + 1000 + 2*(x + 65));
}
int main()
{
    printf("%d\n", convert(-120));
}