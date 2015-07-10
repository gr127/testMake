#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

#define SIG SIGUSR1
#define CLOCKID CLOCK_REALTIME

static void handler (int sig, siginfo_t *si,void *uc){
	printf("Caught signal %d\n",sig);
}

int main(int argc, char *argv[])
{
	sigset_t mask;
	struct sigaction sa;
	struct sigevent sev;
	timer_t timerid;
	struct itimerspec its;
	int b;
	printf("Estabilishing handler for signal %d\n",SIG);
	sa.sa_flags=SA_SIGINFO;
	sa.sa_sigaction=handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIG,&sa,NULL)==-1){
	perror("sigaction");
	return 1;
	}

	sev.sigev_notify=SIGEV_SIGNAL;
	sev.sigev_signo=SIG;
	sev.sigev_value.sival_ptr=&timerid;
	if (timer_create(CLOCKID,&sev,&timerid)==-1){
	perror("timer create");
	return 1;
	}

	printf("timer ID is %ld\n",(long)timerid);
	its.it_value.tv_sec=3;
	its.it_value.tv_nsec=0;
	its.it_interval.tv_sec=1;
	its.it_interval.tv_nsec=0;

	if(timer_settime(timerid,0,&its,NULL)==-1)
	{
	perror("timer_settime");
	return 1;
	}

printf("Sleep...\n");
sleep(5);
	printf("Blcking signal %d\n",SIG);
	sigemptyset(&mask);
	sigaddset(&mask,SIG);
	if(sigprocmask(SIG_SETMASK,&mask,NULL)==-1){
		perror("sigprocmask");
	return 1;
	}

	//	b=10;	
//while (b!=0)
//{
//b=sleep(b);	
//}

//printf("lll\n");
	while(1);
	return 0;
}