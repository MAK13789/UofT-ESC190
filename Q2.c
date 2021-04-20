#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hash_function(char *str, int table_size)
{
    int output = 0;
    for (int i = 0; i < strlen(str); i ++)
    {
        output += (int)str[i];
    }
    return output % table_size;
}
char **hash(char **strs, int strs_sz)
{
    //printf("debug\n");
    char **hashtable = (char **)malloc(strs_sz * sizeof(char *));
    for (int k = 0; k < strs_sz; k++)
    {
        hashtable[k] = (char *)malloc((strlen(strs[k]) + 1) * sizeof(char));
    }
    for (int j = 0; j < strs_sz; j++)
    {
        hashtable[j] = "";
    }
    for (int i = 0; i < strs_sz; i ++)
    {
        int index = hash_function(strs[i], strs_sz);
        if (hashtable[index] == "")
        {
            hashtable[index] = strs[i];
        }
        else
        {
            while (hashtable[index] != "")
            {
                index ++;
            }
            hashtable[index] = strs[i];
        }
    }
    return hashtable;
}
int repeats(char **strs, int strs_sz)
{
    char **hashtable = hash(strs, strs_sz);
    for (int i = 0; i < strs_sz; i ++)
    {
        if (hashtable[i] != "")
        {
            int j = i+1;
            while (hashtable[j] == "")
            {
                j ++;
            }
            if (strcmp(hashtable[i], hashtable[j]) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
/*
This function is O(n) because it only loops through the size of the string array, and the only time there is a nested loop is when dealing with the hash table. However, due to the nature
of a hash table, this still takes O(n) time on average. For example, on average it doesn't need to loop through the whole hash table to find an empty spot given an occupied spot
, rather just a small portion of the table
of the hash table.
*/
/*
int main(void){
	
    char *strs1[] = {"ESC", "MAT", "MSE", "CIV"};
	printf("%d\n", repeats(strs1, 4)); // 0
	char *strs2[] = {"ESC", "MAT", "MSE", "CIV", "ESC"};
	printf("%d\n", repeats(strs2, 5)); // 1
	return 0;
    //printf("%d\n", hash_function("CIV", 4)); this function works
*/