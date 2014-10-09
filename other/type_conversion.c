#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc, char** argv)
{
    // 0x10000000
    char a = 128;
    // 1byte to 4byte, copy left-byte 1 to 0xff 0xff 0xff 0x10000000 
    printf("%d\n", a); // -128
    // left-byte 1 not be extended
    printf("%d\n", (unsigned char)a); //128
    
    char* p = &a;
    printf("%x\n", (unsigned int)p); //bfb6a76f
    printf("%p\n", p); //0xbfb6a76f
    printf("%p\n", (void*)p); //0xbfb6a76f
    
    void *pv;
    pv = malloc(4);
    memset(pv,0x11,4);
    printf("%p\n",*(int*)pv); //0x11111111
    *(int*)pv = 120;
    printf("%d\n",*(int*)pv); //120
}
