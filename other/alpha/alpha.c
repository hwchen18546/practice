#include<stdio.h>

int main()
{
    char input;
    scanf("%c",&input);
    if(input >= 'a' && input <= 'z')
        printf("little: convert %c\n",input-'a'+'A');
    else if(input >= 'A' && input <= 'Z')
        printf("big: convert %c\n",input-'A'+'a');
    else if(input >= '0' && input <= '9')
        printf("number\n");
    else
        printf("nothing\n");
    return 0;
}
