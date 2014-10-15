#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int num;
    struct node *next;
}node;

/* make it simple */
node *top = NULL;

void push(int data)
{
    if(top==NULL)
    {
        top = (node*)malloc(sizeof(node));
        top->next = NULL;
        top->data = data;
        top->num = 1;
    }
    else
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->next = top;
        temp->data = data;
        temp->num = top->num +1;
        top = temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("empty\n");
    }
    else
    {
        node *temp = top;
        printf("%d\n",top->data);
        top = top->next;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    push(1);
    push(2);
    pop();
    push(3);
    pop();
    push(4);
    pop();
    pop();
    pop();
    return 0;   
}
