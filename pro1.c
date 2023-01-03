#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

struct check_data
{
    int check;
    char data[SIZE];
} *shared_data;

int main()
{
    int shmid;
    char buffer[SIZE];
    void* shmaddr;



    // 1234 키의 공유메모리 생성
    if ((shmid = shmget((key_t)1234, sizeof(struct check_data), IPC_CREAT | 0666)) == -1) 
    {
        perror("shmid failed");
        exit(1);
    }

    // shmid 공유메모리를 호출 프로세스 메모리 영역으로 첨부 */
    if ((shmaddr = shmat(shmid, (void*)0, 0)) == (void*)-1)
    {
        perror("shmat failed");
        exit(1);
    }

    shared_data = (struct check_data*)shmaddr;

    while (1)
    {
        printf("input data ==> ");
        fgets(buffer, SIZE, stdin);
        strncpy(shared_data->data, buffer, SIZE); // 공유메모리에 데이터 쓰기
        shared_data->check = 1;
	sleep(1);

	    /* 쓴 데이터가 ‘q’이면 */
            if (!strncmp(shared_data->data, "9", 1)) 
            {
                 break;
            }
	
    }

    // 공유메모리를 호출 프로세스의 메모리 영역에서 분리

    if (shmdt(shmaddr) == -1) 
    {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}
