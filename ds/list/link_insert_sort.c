#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

struct node* creat_node(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

int insert(struct node** head, struct node* s1)
{
    node *temp1 = *head;
    node *temp2 = (*head)->next;
    if(s1->data > (*head)->data)
    {
        s1->next = *head;
        *head = s1;
        return 0;
    }
    else
    {
        while(temp2)
        {
            if(s1->data > temp2->data)
            {
                s1->next = temp2;
                temp1->next = s1;
                return 0;
            }
        }
        temp2->next = s1;
        return 0;
    }
}

void print_list(struct node* head)
{
    printf("---------------------\n");
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void main(int argc, char **argv)
{
    // assume head no meaning
    node* head = creat_node(0);
    node* a = creat_node(1);
    node* b = creat_node(2);
    node* d = creat_node(100);
    node* c = creat_node(5);
    insert(&head, a);
    insert(&head, b);
    insert(&head, c);
    insert(&head, d);
    print_list(head);
}

