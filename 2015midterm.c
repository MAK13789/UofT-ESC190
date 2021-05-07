#include <stdio.h>
#include <stdlib.h>
//Question 1d:
/*
int i = 0;
while (i<n)
{
    printf("%d\n", i);
    i++;
}
*/
//Question 2a:
void initArray(int **a, int n)
{
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
    *a = array;
}
//Question 2c:
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * factorial(n-1));
    }
}
//Question 3:
int iIsPalidrome(int *a, int n)
{
    //n is odd:
    if (n % 2 == 1)
    {
        int mid = (n-1)/2;
        for (int i = 0; i < mid; i ++)
        {
            if (a[i] != a[n-1-i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        int mid = n/2;
        for (int i = 0; i < mid; i ++)
        {
            if (a[i] != a[n-1-i])
            {
                return 0;
            }
        }
        return 1;
    }
}

//Question 4a:
int rFindMin(int *a, int i, int n, int *index)
{
    if (i == n - 1)
    {
        if (a[i] <= a[n])
        {
            return a[i];
        }
        else
        {
            return a[n];
        }
    }
    else
    {
        if (a[i] <= rFindMin(a, i+1, n, 0))
        {
            return a[i];
        }
        else
        {
            return rFindMin(a, i+1, n, 0);
        }
    }
}




int main()
{
    //int x = factorial(5);
    //printf("%d\n", x);
    //int a[5] = {1,2,4,2,1};
    //printf("%d", iIsPalidrome((int *)&a, 5));
    int a[5] = {5,4,7,1,3};
    int min = rFindMin((int *)&a, 0, 4, 0);
    printf("%d", min);
}