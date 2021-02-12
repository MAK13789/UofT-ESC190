#include "linkedlists.h"
#include <stdio.h>
#include <stdlib.h>
void insert(struct node *head, int value, int position)
{
    struct node *cur = head;
    for (int i = 0; i < position; i++)
    {
        cur = cur->next;
    }
    struct node *temp = cur->next;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = temp;
    cur->next = new;
}
void delete(struct node *head, int position)
{
    struct node *cur = head;
    for (int i = 0; i < position-1; i++)
    {
        cur = cur->next;
    }
    struct node *temp = cur->next->next;
    cur->next = temp;
}
void free_linked_list(struct node *head)
{
    struct node *cur = head;
    cur->next = NULL;
    free(cur);
}
void print_linked_list(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("\n");
}