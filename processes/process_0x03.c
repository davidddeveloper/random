#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - working with pipes
 * Return: 0 -success
 */
int main(int argc, char **argv)
{
	int fd[2];
	//fd[0] - read
	//fd[1] - write
	int x, id;

	//check if pipe not created successfully
	if(pipe(fd) == -1)
		return (1);

	x = atoi(argv[1]); //convert second cli argument to int

	write(fd[1], &x, sizeof(int)); //write to x

	//create a process
	id = fork();

	if (id == -1) //check if was an error creating the process
		return (1); //return 1 if there was an error

	wait(NULL); //wait for child process to finish executing

	if (id == 0) // child process
	{
		int y;
		int sum = atoi(argv[2]); //convert 3rd cli argument to int

		read(fd[0], &y, sizeof(int)); //read from pipe and store it in y
		//perform operation
		sum = sum + y;
		//write the result to the pipe
		write(fd[1], &sum, sizeof(int));
	}
	else //main process
	{
		int z;

		read(fd[0], &z, sizeof(int)); //read from pipe and store it in z
		printf("%d\n", z); //print result read
	}
	return (0);
}
