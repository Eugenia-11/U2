#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define SIZE 1024

typedef struct msg_buf{
    long type;  // > 0 
    char text[100];
}message;

struct check_data
{
    int check;
    char data[SIZE];
} *shared_data;

int main(void){
    int shmid;
    struct shmid_ds shm_stat;
    void* shmaddr;
    key_t key;
    int msgid, rc; 
    int type_num = 0;
    message msg_buf;

    key = msgget((key_t)1234, IPC_CREAT | 0666);
    
    // 1234 키의 공유메모리 있으면 접근해서 식별자 얻음
    if ((shmid = shmget((key_t)1234, SIZE, IPC_CREAT | 0666)) == -1) 
    {
        perror("shmid failed");
        exit(1);
    }
    
    // shmid 공유메모리를 호출 프로세스 메모리 영역으로 첨부
    if ((shmaddr = shmat(shmid, (void*)0, 0)) == (void*)-1)
    {
        perror("shmat failed");
        exit(1);
    }

    shared_data = (struct check_data*)shmaddr;

    // check가 0이면 공유메모리에 도착한 데이터가 없다는 의미
    shared_data->check = 0;
    
    if(key == -1){
        perror("msgget error");
        return 0;
    }   

    printf("message Q's key is %d\n", key);

    while(1){
        msg_buf.type = ( type_num++ % 3 )+1;
        sprintf(msg_buf.text, "This is msg from Producer %d", type_num);

        rc = msgsnd(key, &msg_buf, sizeof(msg_buf), 0);

        if(rc == -1){
            perror("msgsnd failed");
            return 0;
        }

        printf("%d data sent to queue\n", type_num);
        sleep(2);
        if (shared_data->check) 
        {
            printf("data read from shared memory : %s", shared_data->data);
            shared_data->check = 0;

            /* 읽은 데이터가 ‘q’이면 */
            if (!strncmp(shared_data->data, "9", 1)) 
            {
                 break;
            }
        }
    }
    // 공유메모리를 호출 프로세스의 메모리 영역에서 분리

    if (shmdt(shmaddr) == -1) 
    {
        perror("shmdt failed");
        exit(1);
    }

    // shmid 공유메모리 삭제

    if (shmctl(shmid, IPC_RMID, 0) == -1) 
    {
        perror("shmctl failed");
        exit(1);
    }
    
    return 0;

  }
