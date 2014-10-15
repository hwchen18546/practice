#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

struct stack
{
    int data[STACK_SIZE];
    int top;
};
typedef struct stack stack;

void stack_init(stack *S)
{
    S->top = 0;
}

void stack_push(stack *S,int d)
{
    if(S->top < STACK_SIZE)
        S->data[S->top++] = d;   //S->top++
    else
        printf("Error: stack full\n");
}

int stack_pop(stack *S)
{
    if(S->top != 0)
        return S->data[--S->top];  //--S->top
    else
        printf("Error: stack empty\n");
    return -1;
}

void main(int argc, char **argv)
{
    stack *S = (stack *)malloc(sizeof(stack));
    stack_init(S);
    stack_pop(S);
    stack_push(S,1);
    stack_push(S,2);
    stack_push(S,3);
    printf("stack pop = %d\n",stack_pop(S));
    printf("stack pop = %d\n",stack_pop(S));
    printf("stack pop = %d\n",stack_pop(S));
    printf("stack pop = %d\n",stack_pop(S));
}
