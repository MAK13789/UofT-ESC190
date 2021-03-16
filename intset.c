#include <stdio.h>
#include <stdlib.h>
#include "intset.h"
void intset_create(struct intset **s)
{
    **s = (struct intset *)malloc(sizeof(struct intset));
}
void intset_add(struct intset *s, int *elems, int num_elems)
{
    for (int i = 0; i < num_elems; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = elems[i];
        temp->next = NULL;
        s->next = temp;
        s = s->next;
    }
}
int intset_iselem(struct intset *s, int elem)
{
    while(s != NULL)
    {
        if (s->data == elem)
        {
            return 1;
        }
        s = s->next;
    }
    return 0;
}
void intset_remove(struct intset *s, int elem)
{
    if (intset_iselem(s, elem) == 1)
    {
        while (s->next->data != elem)
        {
            s = s->next;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp = s->next->next;
        free(s->next);
        s->next = temp;
    }
}