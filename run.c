#include "shell.h"
/**
 * run_command - Function to execute command
 *
 * @command: input
 *
 **/

void run_command(const char *command)
{
pid_t sub_id = fork();

if (sub_id == -1)
{
myprinter("There's Error creating process.\n");
exit(EXIT_FAILURE);
}
else if (sub_id == 0)
{
char *args[150];
int arg_count = 0;

char *item = strtok((char *)command, " ");
while (item != NULL)
{
args[arg_count++] = item;
item = strtok(NULL, " ");
}
args[arg_count] = NULL;

execvp(args[0], args);

myprinter("There's error executing command.\n");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

