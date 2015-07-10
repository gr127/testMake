#include "bin_sem.h"


int main(){
	key_t key=ftok("File1.c",1);
	int semid = binary_semaphore_allocation(key,0666 | IPC_CREAT);
if (semid>0){
	printf("pr2: Try take the semid\n");
	binary_semaphore_take(semid);
	printf("pr2: Yeeh, we have taken it\n");
	binary_semaphore_free(semid);
	printf("pr2: and released\n");
	exit(0);
}	


printf("pr2 :Unable to get sem id \n");

exit(1);
}