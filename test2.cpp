#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define SHM_KEY 5678

struct shm_struct
{
    pthread_mutex_t shm_mtx;
    int number;
    int data;
} *shm_s;

int main()
{
    int shmid = 0;
    void* shmaddr;
    pthread_mutexattr_t attr;


    if ((shmid = shmget(SHM_KEY, (size_t)sizeof(shm_struct), IPC_CREAT | 0666)) < 0)
    {
        printf("shmget error!\n");
        return -1;
    }

    if ((shmaddr = shmat(shmid, 0, 0))< (void*) 0)
    {
        printf("shmat error!\n");
        return -1;
    }

    shm_s = (struct shm_struct*)shmaddr;

    if (pthread_mutexattr_init(&attr))
    {
        printf("init mutexattr error!\n");
        return -1;
    }

    if (pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED))
    {
        printf("setpshared mutexattr error!\n");
        return -1;
    }

    if (pthread_mutex_init(&shm_s->shm_mtx, &attr))
    {
        printf("init mutex error!\n");
        return -1;
    }
 
 
    
    while (1)
    {
        shm_s->number = 0;
        shm_s->data = 10000;
        printf("Writer [%d] + data = %d\n", shm_s->number, shm_s->data);
        sleep(1);
    }
    return 0;
}
