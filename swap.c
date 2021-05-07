#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *lchild;
    struct node *rchild;
};
void swap_par_child(struct node *parent, struct node *child){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = child->value;
    temp->lchild = child->lchild;
    temp->rchild = child->rchild;
    child->value = parent->value;
    parent->value = temp->value;
    if(child == parent->rchild){
        child->lchild = parent->lchild;
        child->rchild = parent;
        parent->rchild = temp->rchild;
        parent->lchild = temp->lchild;
    }
    if(child == parent->lchild){
        child->rchild = parent->rchild;
        child->lchild = parent;
        parent->rchild = temp->rchild;
        parent->lchild = temp->lchild;
    }
}
//swapping 2 nodes that aren't parent and child:
void swap(struct node *A, struct node *B)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = B->value;
    temp->lchild = B->lchild;
    temp->rchild = B->rchild;
    B->value = A->value;
    A->value = temp->value;
    B->lchild = A->lchild;
    B->rchild = A->rchild;
    A->lchild = temp->lchild;
    A->rchild = temp->rchild;
}