#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD 50

int count = 0;
void *increment_count(void *arg)
{
    /*
     * 1. Retrieve the value of count
     * 2. Add 1 to this value
     * 3. Store this value to count
     */
    int i;
    for(i=0;i<1000000;i++)
        count = count + 1;
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t my_thread[MAX_THREAD];
    int id; 
    for(id = 0; id < MAX_THREAD; id++)
    {   
        int ret = pthread_create(&my_thread[id], NULL, &increment_count, (void*)id);
        if(ret != 0)
        {   
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }   
    }
    for(id = 0; id < MAX_THREAD; id++)
    {
        pthread_join(my_thread[id], NULL);
    }
    printf("%d\n",count);
    pthread_exit(NULL);
    return 0;
}

