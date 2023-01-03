#include <stdio.h>
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/stat.h> 
#include <stdlib.h>

typedef struct msg_buf{ 
    long type;  // > 0
    char text[100];
}message;

int main(int argc, char **argv)
{
    key_t key_id, rc; 
    message msg_buf;

    int msgtype = atoi(argv[1]);
    printf("Consumer [%d]\n", msgtype);

    key_id = msgget((key_t)1234, IPC_CREAT|0666);
    
    if (key_id < 0) {
        perror("msgget error : ");
        return 0;
    }   
    
    while(1) {
        rc = msgrcv(key_id, &msg_buf, sizeof(msg_buf), msgtype, 0); 
        if(rc == -1){
            perror("msgrcv failed :");
            return 0;
        }

        printf("recv : %s \n", msg_buf.text);

    }   
    return 0;
 }
