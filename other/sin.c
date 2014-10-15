#include<stdio.h>
#include<math.h>

#define PI 3.1415
int main()
{
    printf("%f\n",sin((30.0/180)*PI));
    printf("%f\n",sin((0/180)*PI));
    printf("%f\n",sin(90.0/180*PI));
    return 0;
}
