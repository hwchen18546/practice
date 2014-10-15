#include<stdio.h>

struct commands
{
    int (*fp)(void);
    char key;
};
typedef struct commands commands;

/* Callback Function: 
 * passive, not you active call it
 * but trigger something like KB and return a "callback" fp
 */
int do_a(), do_b(), do_c();

void main (int argc, char** argv)
{
    commands lists[]=
    {
        do_a, 'a',
        do_b, 'b',
        do_c, 'c',
        NULL, '\0'
    };
    char ch;
    while(1)
    {
        ch = getchar();
        commands *comm_pointer;
        comm_pointer = lists;
        while(comm_pointer->fp != NULL)
        {
            if(comm_pointer->key == ch)
            {
                comm_pointer->fp();
                break;
            }
            comm_pointer++;
        }
    }
}

int do_a()
{
    printf("a\n");
    return 0;
}

int do_b()
{
    printf("b\n");
    return 0;
}

int do_c()
{
    printf("c\n");
    return 0;
}
