#include <stdio.h>
#include <stdlib.h>
//Problems 1 and 2:
/*
struct node
{
    int data;
    struct node *next;
};
//Problem 1:
void print_no_rec(struct node *head)
{
    struct node *cur = head;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
//Problem 2:
void print_rec(struct node *head)
{
    struct node *cur = head;
    if (cur == NULL)
    {
        return;
    }
    else
    {
        printf("%d\n", cur->data);
        cur = cur->next;
        print_rec(cur);
    }
}
int main()
{
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 1;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 2;
    node2->next = NULL;
    print_no_rec(node0);
    print_rec(node0);
    free(node0);
    free(node1);
    free(node2);
}
*/
//Problem 3:
struct node
{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; //0 if int, 1 if float, 2 if double
    struct node *next;
}
void append_int(struct node *head, int *value)
{
    struct node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    //cur is now the last element
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->p_data = value;
    new->type = 0;
    new->next = NULL;
    cur->next = new;
}
void append_float(struct node *head, float *value)
{
    struct node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    //cur is now the last element
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->p_data = value;
    new->type = 1;
    new->next = NULL;
    cur->next = new;
}
void append_double(struct node*head, double *value)
{
    struct node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    //cur is now the last element
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->p_data = value;
    new->type = 2;
    new->next = NULL;
    cur->next = new;
}
void print(struct node *head)
{
    struct node *cur = head;
    while (cur->next != NULL)
    {
        if (cur->type == 0)
        {
            printf("%d\n", cur->p_data);
        }
        if (cur->type == 1)
        {
            printf("%f\n", cur->p_data);
        }
        if (cur->type == 2)
        {
            printf("%lf\n", cur->p_data);
        }
        cur = cur->next;
    }
}