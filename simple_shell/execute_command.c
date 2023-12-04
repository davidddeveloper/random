#include "main.h"

/**
 * execute_command - execute a command by contenate each dir wit command
 * @com: the command to find the exe for
 * @path: the list of directory
 *
 * Return: the exact path otherwise 0
 */
int execute_command(char *command, char *argv[], dirs *path)
{
	dirs *head = path;
	char *dir;
	char *end_of_str;
	size_t len;

	while (head != NULL)
	{
		dir = head->dir; //save each node in dir
		end_of_str = dir;
		len = str_len(dir); //calculate the length of dir

		//go to the end of the string
		while(*end_of_str != '\0') end_of_str++;

		//checks if last value before '\0' is not /
		end_of_str--;
		if (*end_of_str != '/')
		{
			dir = strcat(dir, "/"); //concatenates / to dir and save
		}

		//concates the command with the directory
		dir = strcat(dir, command);

		//execute the command
		execve(dir, argv, NULL);
		
		head = head->next; //traverse through the list
	}

	return (0);
}
