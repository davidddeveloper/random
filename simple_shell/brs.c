#include "main.h"
/**
 * main - brainstorm ideas
 * Return: 0 always
 */
int main(void)
{
	/*int len = 0, counter;

	for (counter = 0; *str++ != '\0'; counter++)
		len++;
	return (len);*/
	
	/* remove the null-terminating char */
	/*char *str = "david";
	char *temp = "     ";
	while (*str != '\0')
	{
		temp = str;
		str++;
		temp++;
		
	}
	printf("%s", temp);*/
	/*dirs *head;
	char *paths = getenv("PATH");

	head = create_paths(paths);
	while (head != NULL)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}*/

	char *str = "david";
	char *end_of_str = str;
	while (*end_of_str != '\0') end_of_str++;
	end_of_str--;
 	printf("%s\n", end_of_str);
	end_of_str = str;
	printf("%s", end_of_str);
	return (0);
}
