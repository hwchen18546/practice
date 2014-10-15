// gcc pthread.c -lpthread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD 5

pthread_mutex_t count_mutex;

void *worker_thread(void *arg)
{
    printf("This is worker_thread #%d\n", (int)arg);
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t my_thread[MAX_THREAD];
    int id;
    for(id = 0; id < MAX_THREAD; id++)
    {
        int ret = pthread_create(&my_thread[id], NULL, &worker_thread, (void*)id);
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
    pthread_exit(NULL);
    return 0;
}
