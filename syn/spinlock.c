#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD 50

pthread_spinlock_t spinlock;
int count = 0;
void *increment_count(void *arg)
{
    int i;
    for(i=0;i<100000;i++)
    {
        pthread_spin_lock(&spinlock);
        count = count + 1;
        pthread_spin_unlock(&spinlock);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t my_thread[MAX_THREAD];
    pthread_spin_init(&spinlock, 0);
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
    pthread_spin_destroy(&spinlock);
    return 0;
}

/* Different between spinlock and semaphore
 * spinlock(busy waiting),semaphore(sleep)
 * signal core can't use spinlock(no cpu can release lock)
 * if critical section time is short, spinlock is better
 * because it can avoid context switch time(sleep)    
 */
