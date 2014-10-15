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

struct node* reverse(struct node* head)
{
    struct node* pre_n = NULL;
    struct node* temp = head;
    struct node* nex_n = head->next;
    while(nex_n !=NULL)
    {
        temp->next = pre_n;
        pre_n = temp;
        temp = nex_n;
        nex_n = temp->next;
    }
    temp->next = pre_n;
    return temp;
}

void print_list(struct node* head)
{
    printf("--------------------------------\n");
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(int argc, char **argv)
{
    // assume head no meaning
    struct node* head = creat_node(0);
    struct node* a = creat_node(1);
    struct node* b = creat_node(2);
    struct node* c = creat_node(5);
    insert(head, a);
    insert(a, b);
    insert(b, c);
    print_list(head);
    head = reverse(head);
    print_list(head);
}

