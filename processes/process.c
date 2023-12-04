#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 *  * main - create processes
 *   * Return: 0 success
 *    */
int main(void)
{
	// prints number from one to 10
	// main process prints from 6 - 10
	// child process prints from 1 - 5
	int id = fork();
	int n, i;

	if (id != 0)
		printf("%d - parent id. %d - child id\n", getppid(), getpid());

	if (id == 0)
		n = 1;
	else
		n = 6;
	wait(NULL); //main process wait for child process to finish executing
	//child process also wait but there is no sub process so it continues it execution
	printf("%d process is executing\n", getpid());
	for (i = n; i < n + 5; i++)
		printf("%d \n", i);
	return (0);
}
