#include <stdio.h>
#include <stdlib.h>
//Question 2a:
void describe(int grade)
{
    if ((grade < 0) || (grade > 100))
    {
        printf("Invalid.");
    }
    if ((grade >= 50) && (grade <= 100))
    {
        printf("Pass!");
    }
    if ((grade >= 0) && (grade <= 49))
    {
        printf("Fail...");
    }
}