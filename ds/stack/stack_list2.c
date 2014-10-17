#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int num;
    struct node *next;
}node;

int push(int data,node **top)
{
    node *temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
        return -1;
    temp->next = *top;
    temp->data = data;
    *top = temp;
    return 0;
}

//call by pointer and call by pointer to pointer
int pop(int *data, node **top)
{
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        node *temp = *top;
        *data = (*top)->data;
        *top = (*top)->next;
        free(temp);
        return 0;
    }
}

int main(int argc, char **argv)
{
    node *top = NULL;
    int data;
    push(1,&top);
    pop(&data,&top);
    printf("%d\n",data);
    push(5,&top);
    push(6,&top);
    push(7,&top);
    pop(&data,&top); printf("%d\n",data);
    pop(&data,&top); printf("%d\n",data);
    pop(&data,&top); printf("%d\n",data);
    return 0;   
}

/*
  address(node *top1) -> value
  address(node **top2) -> address -> value
  &top1 = top2;
*/
/*
  a simple way is push and pop return node*
  pop data using call by pointer.
*/
