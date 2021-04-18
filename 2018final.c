#include <stdio.h>
#include <stdlib.h>
//Question 14:
void f1(int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        printf("%d\n", i);
    }
}
//Question 15:
void f2(int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        for (int j = 1; j < n; j ++)
        {
            for (int k = 1; k < n; k++)
            {
                printf("this function is O(n^2)logn\n");
            }
        }
    }
}
int main()
{
    f1(1000);
    f2(100);
}