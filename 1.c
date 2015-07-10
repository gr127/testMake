
/*create pipe
make fork
close deskriptor

child
close exit desk
read in

PID
информация из 
*/
#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	printf("Im parent %d\n", getpid());
	switch (pid=fork()){
	case -1:
	printf("Error fork\n");
	return -1;
	case 0:
	printf ("Child process after fork %d\n",getpid());
	return 0;
	default:
	printf("Parent after Fork %d\n",getpid());
	}
} 
