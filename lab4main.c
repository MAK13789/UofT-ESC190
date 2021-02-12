#include <stdio.h>
#include <stdlib.h>
#include "linkedlists.h"
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    head->next = node1;
    node1->data = 4;
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 7;
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node2->next = node3;
    node3->data = 9;
    node3->next = NULL;
    print_linked_list(head);
    insert(head, 3, 2);
    print_linked_list(head);
    delete(head, 2);
    print_linked_list(head);
    free_linked_list(head);
}