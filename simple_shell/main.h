#ifndef MAIH_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 * Prototypes
 */
typedef struct dir {
	char *dir;
	struct dir *next;
} dirs;

dirs *create_paths(char *path);
int execute_command(char *command, char *argv[], dirs *path);
int str_len(char *str);
#endif /* MAIN_H */
