#include "main.h"

/**
 * main - print current working dir
 *
 * Return: 0 always
 */
int main(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);

	return (0);
}
