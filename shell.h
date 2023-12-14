#ifndef SHELL_H
#define SHELL_H

/**
 * Preprocessor - directive
 * for library file
 *
 * prototype
 **/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct inbuilt_command
{
	char *command_string;
	int (*lego)();
} inbuilt_command_t;


int (*inbuilt(char *command))();
int _exit(char **items, env_t *linkedlist, char *buffer);
int _env(char **items, env_t *environment);
int _cd(char **items);





char *_getenv(const char *tag);
int _setenv(const char *tag, const char *val, int turn);








void showPrompt(void);
read_input(char *command, COM_MAX_LEN);
run_command(command);

#endif

