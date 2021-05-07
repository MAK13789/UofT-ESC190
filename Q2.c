#include <stdio.h>
#include <stdlib.h>
int my_strncmp (char *str1, char *str2, int num)
{
    if (num == 0)
    {
        if (str1[0] < str2[0])
        {
            return -1;
        }
        else if (str1[0] > str2[0])
        {
            return 1;
        }
        else if (str1[0] == str2[0])
        {
            return 0;
        }
    }
    //what if the string terminaates
    if (str1[0] < str2[0])
    {
        return -1;
    }
    else if (str1[0] > str2[0])
    {
        return 1;
    }
    else
    {
        int length1 = 0;
        while (str1[length1] != '\0')
        {
            length1++;
        }
        char str1new[length1]; //will this already have the '\0'??
        for (int i = 1; i < length1; i++)
        {
            str1new[i-1] = str1[i];
        }


        int length2 = 0;
        while (str2[length2] != '\0')
        {
            length2++;
        }
        char str2new[length2]; //will this already have the '\0'??
        for (int j = 1; j < length2; j++)
        {
            str2new[j-1] = str2[j];
        }
        return my_strncmp((char *)&str1new, (char *)&str2new, num-1); 
    }
}
/*
int main()
{
    int test = my_strncmp("ESC180", "ESC190", 3);
    printf("%d", test);
}
*/