struct node
{
    int data;
    struct node *next;
};
void insert(struct node *head, int value, int position);
void delete(struct node *head, int position);
void free_linked_list(struct node *head);
void print_linked_list(struct node *head);