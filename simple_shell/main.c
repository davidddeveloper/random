#include "main.h"

/**
 * main - creates a simple shell
 * @ac: the number of arguments passed to main
 * @av: array containing the strings of argument passed to main
 *
 * Return: 0 - always
 */
int main(int ac, char **av)
{
	//setenv("TERM", "xterm-256color", 1);
	//checks if we're running on interactive mode
	if (isatty(STDIN_FILENO)) //alternatively (STDIN_FILENO + 1)
	{
		char cwd[1024]; //working dir
		char *username; //login user
		char hostname[1024]; //environment
		char *command; //holds the command the user typed
		char *modifyCommand;
		char *temp;
		size_t size_of_com = 32;
		char *token;
		char *delm = " ";
		char *toks[1024]; //arr of tokens
		int counter = 0;
		int pid_one;
		char *paths_str;
		dirs *paths; //pointer to a struct
		
		getcwd(cwd, sizeof(cwd));
		username = getlogin();
		gethostname(hostname, sizeof(hostname));

		paths_str = getenv("PATH"); //ENVIRONMENT VARIABLES
		paths = create_paths(paths_str); //tokenized and create a linked lists
		while (1)
		{
			printf("%s@%s:%s$ ", username, hostname, cwd); //prompt the user
		
			//read input from the user
			getline(&command, &size_of_com, stdin);

			//remove the \n in the command
			command = strtok(command, "\n");
			
			//tokenizing the commands and storing it inside of an array
			token = strtok(command, delm);
			//printf("%s\n", token);
			while (token != NULL)
			{
				toks[counter] = token; //save the token in toks array
				token = strtok(NULL, delm); //subsequent call
				counter++;
			}

			//execution phase
			pid_one = fork(); //started a child process
			if (pid_one != 0)
				wait(NULL); //wait until the child process finish
			if (pid_one == 0)
			{
				//char *const *argv = toks;
				//toks[0] = "./cwd";
				if (toks[1] == NULL)
					toks[1] == toks[0];

				execute_command(toks[0], toks, paths);

			}

			//reset the shell after the first loop
			command = "";
			token = "";
			while (counter--)
				toks[counter] = 0;
			counter = 0;


		}
	}
	else
	{
		printf("Were're not running on interactive mode. \n");
	}
	return (0);
}
