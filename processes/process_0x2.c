#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	int id = fork();

	if (id == 0)
		sleep(30);
	printf("PPID: %d. PID %d\n", getppid(), getpid());
	
	wait(NULL);
}
