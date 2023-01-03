#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>


#define SIZE 1024

struct check_data
{
    int check;
    char data[SIZE];
} *shared_data;

typedef struct msg_buf{
    int type;  // > 0 
    char text[100];
}message;

int main()
{
    int shmid;
    struct shmid_ds shm_stat;
    void* shmaddr;
    
    int even[4];
    int odd[5];
    int i,j=0;
    
    key_t key;
    int msgid, rc; 
    //int type_num = 0;
    message msg_buf;
    
    
   

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
    


    while (1) {

        /* 공유메모리에 데이터 도착하면 */

        if (shared_data->check) 
        {
            printf("data read from shared memory : %s",shared_data->data); 
            sleep(1);
            shared_data->check = 0;
            
            
            if ((atoi(shared_data->data))%2==0)
            	msg_buf.type=2;
            else 
            	msg_buf.type=1; 
            	

            //mesage q in put
            sprintf(msg_buf.text, "This is msg from Producer %d",atoi(shared_data->data));
            rc = msgsnd(key, &msg_buf, sizeof(msg_buf), 0);
            
           
            printf("%s data sent to queue\n", shared_data->data);
            sleep(1);


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
