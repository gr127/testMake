#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

int sum;

void *print_hello (void *num)
{
long t_num;
t_num=(long) num;
int i;
long int id;
/*for(i=0;i<10;i++)
{
	id=(long int)pthread_self();
	printf("ID: %ld\n",t_num);
	printf("Hello World! Thread num: %ld\n", id);
	sleep(1);
	}*/
}

void *plus(void *num)
{
	sum++;
}

void *minus(void *num)
{
	sum=sum-2;
}

int main(int argc, char *argv[])
{
pthread_t threads[NUM_THREADS];
sum=20;
int rc;
long t;

t=0;
printf("IN main:creating thread %ld\n",t);
rc=pthread_create(&threads[t],NULL,plus, (void *) t);
	
t=1;
printf("IN main:creating thread %ld\n",t);
rc=pthread_create(&threads[t],NULL,minus, (void *) t);

for (t=0;t<NUM_THREADS;t++){
	pthread_join (threads[t], NULL);
	printf("thread #%ld finished\n", t);
}
printf("CHISLO: %d\n",sum);
return 0;

}
