#include <stdio.h>

//Question 1:
void set_value(int* x)
{
    *x = 10;
}
int main()
{
    int a = 5;
    set_value(&a);
    printf("%d", a);
    return 0;
}

/*
//Question 2:
void insertion_sort(int x[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i-1; j >= 1; j--)
        {
            if (x[j-1] > x[j])
            {
                int tmp = x[j];
                x[j] = x[j-1];
                x[j-1] = tmp;
            }
        }
    }
}
int main()
{
    int a[11] = {4, 3, 2, 10, 12, 1, 5, 6, -11, 12, 11};
    int N = sizeof(a)/sizeof(a[0]);
    insertion_sort(a, N);
    printf("{");
    for (int i = 0; i < N; i++)
    {
        printf("%d", a[i]);
        if (i < N-1)
        {
            printf(",");
        }
    }    
    printf("}");
    return 0;
}    
*/