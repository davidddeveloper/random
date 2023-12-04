#include "main.h"

/**
 * create_paths - create a linked list of directories
 * @path: a string containing the path
 *
 * Return: the list otherwise 0
 */
dirs *create_paths(char *path)
{
	char *dir;
	dirs *head = NULL, *current;

	dir = strtok(path, ":");
	if (dir == NULL) return (0);
	
	while (dir != NULL)
	{
		//allocate memory for the new node
		dirs *new_dir = (dirs*) malloc(sizeof(dirs)); //so we can do new_dir->

		new_dir->dir = strdup(dir);
		new_dir->next = NULL;
		
		if (head == NULL)
		{ //initialize head and current
			head = new_dir; //start of the list
			current = new_dir;
		}
		else
		{
			current->next = new_dir; //changing the next of new_dir to a new dir
			current = new_dir; //keep track of current node
		}

		dir = strtok(NULL, ":");
	}

	return (head);
}
