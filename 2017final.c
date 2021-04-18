/*
struct Node{
    int data;
    struct Node *next;
};
*/
#include <stdio.h>
#include <stdlib.h>
/*
float average_ll(struct node* L, int* n)
{
    if(L->next == NULL)
    {
        (*n)++;
        return L->data;
    }
    else
    {
        (*n)++;
        if(*n == 1)
        {
            float total = average_ll(L->next, n) + L-> data;
            return total / *n;
        }
        return average_ll(L->next, n) + L->data;
    }
}
*/
struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
int sumBST(struct Node *root)
{
    if (root->lchild == NULL && root->rchild != NULL)
    {
        if (root->data > 10)
        {
            return root->data + sumBST(root->rchild);
        }
        else
        {
            return sumBST(root->rchild);
        }
        
    }
    else if (root->rchild == NULL && root->lchild != NULL)
    {
        if (root->data > 10)
        {
            return root->data + sumBST(root->lchild);
        }
        else
        {
            return sumBST(root->lchild);
        }
    }
    else if (root->rchild == NULL && root->lchild == NULL)
    {
        if (root->data > 10)
        {
            return root->data;
        }
        else
        {
            return 0;
        }
    }
    else if (root->rchild != NULL && root->lchild != NULL)
    {
        if (root->data > 10)
        {
            return root->data + sumBST(root->rchild) + sumBST(root->lchild);
        }
        else
        {
            return sumBST(root->rchild) + sumBST(root->lchild);
        }
    }
}
/*
int main()
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 19;
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    root->lchild = node1;
    node1->data = 5;
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    root->rchild = node2;
    node2->data = 20;
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));
    node1->lchild = node3;
    node3->data = 2;
    struct Node *node4 = (struct Node *)malloc(sizeof(struct Node));
    node1->rchild = node4;
    node4->data = 18;
    node3->lchild = NULL;
    node3->rchild = NULL;
    node4->lchild = NULL;
    node4->rchild = NULL;
    printf("%d\n", sumBST(root));
}
*/
/*
int main(void)
{
    // Setting up quick test for Question 3
    struct Node bst1; struct Node bst2; struct Node bst3; struct Node bst4; struct Node bst5;
    bst1.data = 19; bst1.lchild = &bst2; bst1.rchild = &bst3;
    bst2.data = 5; bst2.lchild = &bst4; bst2.rchild = &bst5;
    bst3.data = 20; bst3.lchild = NULL; bst3.rchild = NULL;
    bst4.data = 2; bst4.lchild = NULL; bst4.rchild = NULL;
    bst5.data = 18; bst5.lchild = NULL; bst5.rchild = NULL;
    printf("Sum = %i\n", sumBST(&bst1));
}
*/