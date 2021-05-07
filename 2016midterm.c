#include <stdio.h>
#include <stdlib.h>
//Question 1a and b:
//not applicable
//Question 1c:
void f(int a)
{
    int i = 1;
    if ((a<3) && ((a>=-1) || (a<-2)))
    {
        i = 0;
    }
    printf("%d\n", a+i);
}
//Question 1d-j:
//not applicable
//Question 2a:
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n-2) + fib(n-1);
    }
}
//Question 2b:
//not applicable
//Question 2c:
int sumFib(int n, int s)
{
    //the variable s is the current sum of the sequence, so the first time that the function is called s should be input as 0
    if (n == 0)
    {
        return s;
    }
    else
    {
        int sum = s + fib(n);
        return sumFib(n-1, sum);
    }
}
//Question 3a:
int **initStructure(int r, int *a)
{
    int **matrix = (int **)malloc(sizeof(int*) * r);
    for (int i = 0; i<r; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*a[i]);
        for (int j = 0; j<a[i]; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
//Question 4:
int findLargestSum(int *array, int n, int *a, int *b)
{
    int cur = array[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j ++)
        {
            sum = sum + array[j];
            if (sum > cur)
            {
                cur = sum;
            }
        }
        sum = 0;
    }
    return cur;
}
int main()
{
    int array[8] = {-2,-3,4,-1,-2,1,5,-3};
    int x = findLargestSum((int *)&array, 8, 0, 0);
    printf("%d", x);
}