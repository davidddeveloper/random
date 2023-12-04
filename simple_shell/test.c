#include "main.h"

/**
 * main - test other functions
 *
 * Return: 0 always
 */
int main(void)
{
	/* Test one */
	/*char *path = getenv("PATH");
	dirs *head = create_paths(path);
	printf("starting\n");
	while (head != NULL)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}*/

	/* Test two */
	char *com = "python";
	char *arr[1024] = {com};
	char *path_str = getenv("PATH");
	dirs *paths;
	pid_t pid = fork();

	paths = create_paths(path_str);

	wait(NULL);
	if (pid == 0)
		execute_command(com, arr, paths);
	printf("Program finish execution");
	return (0);
}
