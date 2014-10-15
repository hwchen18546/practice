#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD 50

pthread_mutex_t count_mutex;
int count = 0;
void *increment_count(void *arg)
{
    int i;
    for(i=0;i<1000000;i++)
    {
        pthread_mutex_lock(&count_mutex);
        count = count + 1;
        pthread_mutex_unlock(&count_mutex);
    }
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
    pthread_mutex_destroy(&count_mutex);
    return 0;
}

/* Different between critical section & mutex in windows/linux 
 * In Windows, a critical section is local to your process. 
 * A mutex can be shared/accessed across processes. 
 * Basically, critical sections are much cheaper.
 * Can't comment on Linux specifically, 
 * but on some systems they're just aliases for the same thing.
 */
