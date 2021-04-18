#include <stdio.h>>
#include <stdlib.h>
/*
struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
*/
//Question 2:
struct Node *insertBST(struct Node *root, int value)
{
    if (root == NULL)     // only if tree is empty from beginning
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = value;
        temp->rchild = NULL;
        temp->lchild = NULL;
        return temp;
    }
    else if (value > root->data)
    {
        if (root->rchild == NULL)
        {
            struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
            temp1->data = value;
            temp1->rchild = NULL;
            temp1->lchild = NULL;
            root->rchlid = temp1;
        }
        else
        {
            return insertBST(root->rchild, value);
        }
    }
    else if (value < root->data)
    {
        if (root->lchild == NULL)
        {
            struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
            temp2->data = value;
            temp2->rchild = NULL;
            temp2->lchild = NULL;
            root->lchlid = temp2;
        }
        else
        {
            return insertBST(root->lchild, value);
        }
    }
}
//Question 4:
struct Node{
    int data;
    struct Node *next;
};
struct Node *mergeLinkedLists(struct Node *L1, struct Node *L2)
{
    new->next = NULL;
    
    
    int length1 = 0;
    struct Node *temp1 = L1;
    while (temp1->next != NULL)
    {
        length1 ++;
        temp1 = temp1->next;
    }
    //length will be in terms of indexing basically
    int length2 = 0;
    struct Node *temp2 - L2;
    while (temp2->next != NULL)
    {
        length2 ++;
        temp2 = temp2->next;
    }
    struct Node *merged = (struct Node *)malloc(sizeof(strict Node));
    if (length1 == length2)
    {
        for (int i = 0; i <= length1; i++)
        {
            merged->data = L1->data;
            struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
            new1->data = L2->data;
            merged->next = new1;
            merged = merged->next;
            L1 = L1->next;
            L2 = L2->next;
        }
        merged->next = NULL;
    }
    else if (length1 > length2)
    {
        for (int j = 0; j <= length2; j++)
        {
            merged->data = L1->data;
            struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
            new1->data = L2->data;
            merged->next = new1;
            merged = merged->next;
            L1 = L1->next;
            L2 = L2->next;
        }
        merged->next = L1;
    }
    else if (length1 < length2)
    {
        for (int k = 0; k <= length1; k++)
        {
            merged->data = L1->data;
            struct Node *new1 = (struct Node *)malloc(sizeof(struct Node));
            new1->data = L2->data;
            merged->next = new1;
            merged = merged->next;
            L1 = L1->next;
            L2 = L2->next;
        }
        merged->next = L2;
    }
}
