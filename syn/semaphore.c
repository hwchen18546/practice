#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#define MAX_THREAD 50

//pthread_mutex_t count_mutex;
sem_t bin_sem;

int count = 0;
void *increment_count(void *arg)
{
    int i;
    for(i=0;i<100000;i++)
    {
        //pthread_mutex_lock(&count_mutex);
        sem_wait(&bin_sem);
        count = count + 1;
        //pthread_mutex_unlock(&count_mutex);
        sem_post(&bin_sem);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int pshared = 0; // 0:share threads, other:share process
    int sem_counter = 1; // initial value of the semaphore counter 
    int ret = sem_init(&bin_sem, pshared, sem_counter);
    if(ret != 0)
    {
        printf("Error: sem_init() failed\n");
        exit(EXIT_FAILURE);
    }

    pthread_t my_thread[MAX_THREAD];
    int id; 
    for(id = 0; id < MAX_THREAD; id++)
    {   
        ret = pthread_create(&my_thread[id], NULL, &increment_count, (void*)id);
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
/* What's different between mutex & semaphore
 * 1. mutex is like a lock. only have key process/thread can lock & unlock
 * 2. semaphore is signal, you are receiver(wait) or sender(post) in one time
 * 3. semaphore allow over 1 process/thread access(sem_counter)
 */

/* Different between mutex & binary semaphore(sem_counter = 1)
 * mutex only the process who has key can release resourse (owner)
 * binary semaphore other process can release resourse 
 * semaphore just avoid to access in the same time. mutex has concept of owner.
 */
