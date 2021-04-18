#include <stdio.h>
#include <stdlib.h>
/*
struct Node{
    int data;
    struct Node *next;
};
*/
int is_sorted(struct node *l1)
{
    //0 if false (not sorted), 1 if true (sorted)
    while (l1->next != NULL)
    {
        if (l1->data > l1->next->data)
        {
            return 0;
        }
        l1 = l1->next;
    }
    return 1;
void bubbleSort(struct Node **l1)
{
    if (is_sorted(*l1) == 1)
    {
        return;
    }
    else
    {
        int length = 0;
        while ((*l1)->next != NULL)
        {
            length ++;
            *l1 = (*l1)->next;
        }
        struct Node **temp = l1;
        for (int i = 0; i < length; i ++)
        {
            if ((*l1)->data > (*l1)->next->data)
            {
                //getting the previous node:
                while ((*temp)->next != (*l1))
                {
                    *temp = (*temp)->next;
                }
                struct Node **temp2 - (*l1)->next;
                (*l1)->next = (*l1)->next->next;
                (*temp)->next = *temp2;
                temp2->next = (*l1)->next;
            }
        }
        bubbleSort(l1);
    }
}
struct Node{
    int height;
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
struct Node *rightRotate(struct Node *n);
struct Node *leftRotate(struct Node *n);
int height(struct Node *n);
int max(int i, int j);
void set_balance_factor(struct Node *n)
{
    n->data = (height(n->lchild) - height(n->rchild));
}
void inorder(struct Node *n)
{
    if (n == NULL)
    {
        return;
    }
    inorder(n->lchild);
    set_balance_factor(n);
    inorder(n->rchild);
}
void helper(struct Node *n)
{
    if (n == NULL)
    {
        return;
    }
    helper(n->lchild)
    if (n->data > 1)
    {
        n = rightRotate(n);
    }
    else if (n->data < 1)
    {
        n = leftRotate(n);
    }
    helper(n->rchild);
}
struct Node *balanceBST(struct Node *n)
{
    //find balance factors and place them in the data part of the struct
    inorder(n);
    helper(n);
}
