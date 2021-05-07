#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat_all(char **strs, int str_sz)
{
    int length = 0;
    for (int i = 0; i < str_sz; i++)
    {
        length += strlen(strs[i]);
    }
    length += 1;
    char *output = (char *)malloc(length * sizeof(char));
    strcpy(output, strs[0]);
    for (int j = 1; j < str_sz; j++)
    {
        strcat(output, strs[j]);
    }
    return output;
}
/*
int main()
{
    char *strs[] = {"ESC", "MAT", "MSE", "CIV"};
    char *all = concat_all(strs, 4); 
    printf("%s\n", all);
    free(all);
}
*/