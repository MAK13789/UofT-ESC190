#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct catalogItem {
    char *title;
    struct catalogItem *left;
    struct catalogItem *right;
    char *data;
    int height;
} catalogItem;
char *find(catalogItem *root, char *title)
{
    if (root == NULL)
    {
        return "";
    }
    if (strcmp(root->title, title) == 0)
    {
        return root->data;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        return find(root->right, title);
    }
    else if (root->right == NULL && root->left != NULL)
    {
        return find(root->left, title);
    }
    else if (root->right != NULL && root-> left != NULL)
    {
        if (find(root->left, title) == "")
        {
            return find(root->right, title);
        }
        else
        {
            return find(root->left, title);
        }
    }
}
typedef struct doubleNode {
    int data;
    struct doubleNode *prev;
    struct doubleNode *next;
} doubleNode;
void prepend(doubleNode **head, int data)
{
    doubleNode *new = (doubleNode *)malloc(sizeof(doubleNode));
    new->data = data;
    (*head)->prev = new;
    new->next = (*head);
    (*head) = new;
}
bool deleteNode(doubleNode **head, int val)
{
    if ((*head) == NULL)
    {
        return false;
    }
    else
    {
        int length = 0;
        doubleNode **temp = head;
        while ((*temp)->next != NULL)
        {
            (*temp) = (*temp)->next;
            length ++;
        }
        for (int i = 0; i <= length; i++)
        {
            if ((*head)->data == val)
            {
                doubleNode *before = (*head)->prev;
                doubleNode *after = (*head)->next;
                before->next = after;
                if (after != NULL)
                {
                    after->prev = before;
                }
                free(head);
                return true;
            }
        }
        return false;
    }
}
typedef struct avlNode {
    int val;
    struct avlNode *left;
    struct avlNode *right;
    int height;
} avlNode;