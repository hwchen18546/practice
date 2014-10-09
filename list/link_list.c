#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* creat_node(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert(struct node* n1, struct node* n2)
{
    n2->next = n1->next;
    n1->next = n2;    
}

struct node* insert_to_tail(struct node* head, struct node* n2)
{
    struct node* temp = head;
    // Case1: first 1
    if(head == NULL)
    {
        head == n2;
        return head;
    }
    // Case2: other
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n2;
        n2->next = NULL;
        return head;
    }
}

struct node* delete(struct node* head, struct node* n2)
{
    struct node* temp = head;
    // Case1: first 1
    if(head == n2)
    {
        head = head->next;
        return head;
    }
    else
    {
        while(temp->next != n2)
        {
            temp = temp->next;
        }
        // Case2: last 1
        if(n2->next == NULL)
        {
            temp->next == NULL;
        }
        // Case3: middle
        else
        {
            temp->next == n2->next;
        }
        return head;
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
    struct node* head = creat_node(0);
    struct node* a = creat_node(1);
    struct node* b = creat_node(2);
    struct node* c = creat_node(5);
    insert(head, a);
    head = delete(head, head);
    print_list(head);
    head = insert_to_tail(head, b);
    print_list(head);
    head = insert_to_tail(head, c);
    print_list(head);
}

