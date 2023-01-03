#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t number_lock = PTHREAD_MUTEX_INITIALIZER;

int number;

void *decay_number(void *t)
{
	// mutex lock
	pthread_mutex_lock(&number_lock);
	for (int i = 0; i < 10000; i++)
	{
		number = number + 1;
	}
	// mutex unlock
	pthread_mutex_unlock(&number_lock);
}

void *grow_number(void *t)
{
	// mutex lock
	pthread_mutex_lock(&number_lock);
	for(int i = 0; i < 10000; i++)
	{
		number = number + 1;
	}
	// mutex unlock
	pthread_mutex_unlock(&number_lock);
}

int main() 
{
	for(int a = 0; a < 10; a++)
	{
		number = 0;
	
		void *result;
	       	int t_id;
	       
		pthread_t p_thread[2];
		
		t_id = pthread_create(&p_thread[0], NULL, decay_number, NULL);
			
		if(t_id < 0)
		{
			perror("create error");
			exit(0);
		}

		t_id = pthread_create(&p_thread[1], NULL, grow_number, NULL);
		if(t_id < 0)
		{
			perror("creat error");
			exit(0);
		}
		
		pthread_join(p_thread[0], &result);
		pthread_join(p_thread[1], &result);
			
		printf("result: %d\n\n", number);
		sleep(1);
	}
	return 0;
}
