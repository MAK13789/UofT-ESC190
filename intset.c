#include <stdio.h>
#include <stdlib.h>
#include "intset.h"
void intset_create(struct intset **s)
{
    *s = (struct intset *)malloc(sizeof(struct intset));
    (*s)->head = NULL;
}
void intset_add_one(struct intset *s, int elem)
{
    if (s->head == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = elem;
        new->next = NULL;
        s->head = new;
    }
    else if (intset_iselem(s, elem) == 1)
    {
        return;
    }
    else
    {
        struct node *cur = s->head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = elem;
        new1->next = NULL;
        cur->next = new1;
    }
}
void intset_add(struct intset *s, int *elems, int num_elems)
{
    for (int i = 0; i < num_elems; i ++)
    {
        intset_add_one(s, elems[i]);
    }
}
int intset_iselem(struct intset *s, int elem)
{
    if (s->head == NULL)
    {
        return 0;
    }
    while (s->head->next != NULL)
    {
        if (s->head->data == elem)
        {
            return 1;
        }
        s->head = s->head->next;
    }
    return 0;
}
void intset_remove(struct intset *s, int elem)
{
    if (intset_iselem(s, elem) == 1)
    {
        while (s->head->next != NULL)
        {
            if (s->head->next->data == elem)
            {
                struct node *prev = s->head;
                struct node *after = s->head->next->next;
                struct node *del = s->head->next;
                prev->next = after;
                free(del);
                return;
            }
        }
    }
}
void intset_union(struct intset *s1, struct intset *s2, struct intset **s3)
{
    intset_create(s3);
    while (s1->head->next != NULL)
    {
        if (intset_iselem(*s3, s1->head->data) == 0)
        {
            intset_add_one(*s3, s1->head->data);
        }
        s1->head = s1->head->next;
    }
    while (s2->head->next != NULL)
    {
        if (intset_iselem(*s3, s2->head->data) == 0)
        {
            intset_add_one(*s3, s2->head->data);
        }
        s2->head = s2->head->next;
    }
}