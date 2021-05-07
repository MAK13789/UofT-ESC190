#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//Problem 1:
char *my_strcat(char *dest, char *src)
{
    int dest_len = 0;
    while (dest[dest_len] != '\0')
    {
        dest_len ++;
    }
    int src_len = 0;
    while (src[src_len] != '\0')
    {
        src_len ++;
    }
    for (int i = 0; i <= src_len; i++)
    {
        dest[dest_len + i] = src[i];
    }
    return dest;
}
//Problem 2:
int my_strcmp_rec(char *str1, char *str2)
{
    if (str1[0] == '\0' && str2[0] == '\0')
    {
        return 0;
    }
    else
    {
        if (str1[0] != str2[0])
        {
            return (str1[0] - str2[0]);
        }
        if (str1[0] == str2[0])
        {
            return (my_strcmp_rec((str1+1), (str2+1)));
        }
    }
}
//Problem 3:
/*
int new_atoi(char *str)
{
    int str_len = 0;
    while (str[str_len] != '\0')
    {
        str_len ++;
    }
    int output = 0;
    for (int i = 0; i <= str_len; i++)
    {
        if (isdigit(str[i]) == 1)
        {
            int temp = (str[i]-'0');
            int multiplier = pow(10, (str_len-i));
            int final = temp*multiplier;
            output = output + final;
        }
    }
    return output;
}
*/
int new_atoi(char *str)
{
    int output = 0;
    while (*str)
    {
        output = output*10 + (*str - '0');
    }
    return output;
}
/*
//Problem 4:
struct node
{
    int num;
    struct node *next;
};
int find_cycle(struct node *head)
{
    struct node *start = head;
    struct node *tortoise = head->next;
    struct node *hare = head->next->next;
    while (tortoise != hare)
    {
        if (hare->next == NULL || tortoise->next->next == NULL)   
        {
            break;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    struct node *ptr1 = start;
    while (ptr1 != tortoise)
    {
        ptr1 = ptr1->next;
        tortoise = tortoise->next;
        if (tortoise == NULL)
        {
            return 0;
        }
    }
    return 1;
}
*/
// Problem 4
struct node{
    int data; 
    struct node *next; 
};
int floyd(struct node *head) {
    struct node *tortoise = head;
    struct node *hare = head->next;

    while(tortoise != hare && tortoise != NULL && hare->next != NULL
    && hare->next->next != NULL){
        // iterate at different speeds
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    if(hare->next == NULL || tortoise == NULL || hare->next->next == NULL){
        return 0;
    }
    return 1;
}

int main()
{
    //testing problem 1:
    char destination[100] = "test:";
    char source[100] = " poggers";
    char *new = my_strcat(destination, source);
    printf("%s\n", new);
    //testing problem 2:
    char string1[100] = "hello";
    char string2[100] = "hello";
    int result = my_strcmp_rec(string1, string2);
    printf("%d\n", result);
    //testing problem 3:
    char string[100] = "1234";
    int int_string = new_atoi(string);
    printf("%d\n", int_string);
    //for some reason it messes up the last digit and doesn't work properly if there are more than 3 non digits or if the string is long
    //testing problem 4:
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->num = 3;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->num = 4;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->num = 5;
    node2->next = node1;   //no cycle if its NULL, and there is a cycle if its another node
    int x = find_cycle(node0);
    printf("%d\n", x);
}