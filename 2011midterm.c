#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Question 1f:
int count_pos(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {   
            count ++;
        }
    }
    return count;
}
//Question 1g:
void set_time(long seconds_since_midnight, short *hours)
{
    *hours = seconds_since_midnight / 3600;
}
int palindrome(const char *str)
{
    int length = strlen(str);
    for (int j = 0; j < length/2; j++)
    {
        if (str[j] != str[length-j-1])
        {
            return 0;
        }
    }
    return 1;
}
//Question 1m:
/*
char *concat(const char *s1, const char *s2)
{
    int length = strlen(s1) + strlen(s2) + 1;
    char *str = (char *)malloc(sizeof(char) * length);
    strcat(s1, s2);
    strcpy(str, s1);
    return str;
}
*/
//Question 3:
#define N 5
// Print the magic square.
// Parameters and preconditions: square != NULL points to the magic square array
void print_square(int square[N][N])
{
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            printf(" %3d", square[i][j]);
            // Note: "%3d" prints each integer using at least 3 characters,
            // padded with spaces as necessary.
        printf("\n");
}
}
// Create and print an N x N magic square.
void magic_square(void)
{
    int square[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            square[i][j] = 0;
        }
    }
    square[0][(N-1)/2] = 1;
    int cur_y = 0;
    int cur_x = (N-1)/2;
    for (int k = 2; k <= N*N; k++)
    {
        int old_y = cur_y;
        int old_x = cur_x;
        if (cur_y-1 < 0)
        {
            cur_y = cur_y-1+N;
        }
        else
        {
            cur_y = cur_y - 1;
        }
        if (cur_x + 1 > N-1)
        {
            cur_x = cur_x + 1 - N;
        }
        else
        {
            cur_x = cur_x + 1;
        }
        if (square[cur_y][cur_x] == 0)
        {
            square[cur_y][cur_x] = k;
        }
        else
        {
            if (old_y + 1 > N-1)
            {
                old_y = old_y + 1 - N;
            }
            else
            {
                old_y = old_y + 1;
            }
            square[old_y][old_x] = k;
            cur_y = old_y;
            cur_x = old_x;
        }
    }
    print_square(square);
}
int main(void)
{
    magic_square();
    return 0;
}