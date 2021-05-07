#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
//Question 2:
char *join(int n, const char *strs[], const char *sep)
{
    int length = 0;
    for (int i = 0; i < n; i ++)
    {
        length += strlen(strs[i]);
    }
    length += strlen(sep);
    char *new = malloc((length+1) * sizeof(char));

    strcpy(new, strs[0]);
    for (int j = 1; j < n; j++)
    {
        strcat(new, sep);
        strcat(new, strs[j]);
    }
    return new;
}
/*
int main()
{
    const char *strs[] = {"hi", "there", "you"};
    char *new_str = join(3, strs, "; ");
    printf("%s\n", new_str);
}
/*
//Question 3:
typedef struct list_node {
    long value;
    struct list_node *prev;
    struct list_node *next;
} list_node_t;
bool find(long elem, list_node_t **first)
{
    list_node_t **og_first = first;
    while ((*first)->next != NULL)
    {
        if ((*first)->value == elem)
        {
            list_node_t **temp_node = first;
            list_node_t *node_next = (*first)->next;
            list_node_t *node_prev = (*first)->prev;
            node_prev->next = node_next;
            node_next->prev = node_prev;
            (*temp_node)->prev = NULL;
            (*temp_node)->next = *og_first;
            return true;
        }
        *first = (*first)->next;
    }
    return false;
}
//Question 4:
typedef struct bst_node {
    long value;
    struct bst_node *left;
    struct bst_node *right;
} bst_node_t;
long bst_max(const bst_node_t *root)
{
    bst_node_t *cur_node = root;
    while (cur_node->right != NULL)
    {
        cur_node = cur_node->right;
    }
    return cur_node->value;
}
bst_node_t *clone(const bst_node_t *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        bst_node_t *new = (bst_node_t *)malloc(sizeof(bst_node_t));    
        bst_node_t *og_new = new;
        new->value = root->value;
        if (root->left == NULL)
        {
            new->left == NULL;
        }
        else
        {
            new->left = clone(root->left);
        }
        if (root->right == NULL)
        {
            new->right == NULL;
        }
        else
        {
            new->right = clone(root->right);
        }
        return og_new;
    }
}
/*
int main()
{
    bst_node_t *node1 = (bst_node_t *)malloc(sizeof(bst_node_t));
    node1->value = 10;
    bst_node_t *node2 = (bst_node_t *)malloc(sizeof(bst_node_t));
    node2->value = 5;
    bst_node_t *node3 = (bst_node_t *)malloc(sizeof(bst_node_t));
    node3->value = 15;
    bst_node_t *node4 = (bst_node_t *)malloc(sizeof(bst_node_t));
    node4->value = 12;
    bst_node_t *node5 = (bst_node_t *)malloc(sizeof(bst_node_t));
    node5->value = 69;
    node1->left = node2;
    node2->left = NULL;
    node2->right = NULL;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
    printf("%ld\n", bst_max(node1));
    //it works :eyes:
    bst_node_t *new_root = clone(node1);
    printf("%ld\n", new_root->value);
}
*/
//Question 5:
unsigned hash10(unsigned value)
{
    unsigned sum = 0;
    while (value > 0)
    {
        unsigned m = value % 10;
        sum += m;
        value /= 10;
    }
    if (sum/10 == 0)
    {
        return sum;
    }
    else
    {
        return hash10(sum);
    }
}
/*
int main()
{
    printf("%u\n", hash10((unsigned)1234));
}
*/