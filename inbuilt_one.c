#include "shell.h"
/**
  * inbuilt_one - function to check inbuilt command
  * @command: command
  * Return: success or failure
*/
int (*inbuilt_one(char *command))()
{
unsigned int start;
inbuilt_command_t builds[] = {
{"cd", _cd},
{"alias", _alias},
{"exit", _exit},
{"env", _env},
{"setenv", _setenv_usr},
{"history", _history},
{"bowie", bowie},
{NULL, NULL}
};

start = 0;
while (*builds[start].lego != NULL)
{
if (_strncmp(builds[start].command_string, command,
_strlen(builds[startcommand_string)) == 0)
return (builds[start].lego);
start++;
}
return (NULL);
}
/**
  * _exit - Frees any spaces and exits
  *
  * @linkedlist: Linked list.
  * @buffer: buffer
  * @items: Check user inputs
  *
  * Return: -1 if exit fails.
  */
int _exit(char **items, env_t *linkedlist, char *buffer)
{
unsigned char exit_status;
int start;

for (start = 0; items[1] && items[1][start]; start++)
{
if (!_isdigit(items[1][start]))
{
myprinter("put number\n");
break;
}
}
exit_status = items[1] && start >=
_strlen(items[1]) ? _atoi(items[1]) : 0;
if (linkedlist && buffer && items)
{
free_list(linkedlist);
linkedlist = NULL;
free(buffer);
buffer = NULL;
free(items);
items = NULL;
}
exit(exit_status);
return (-1);
}
/**
  * _env - function to print environment
  * @items: token
  * @environment: environment
  * Return: success or failure
  */
int _env(char **items, env_t *environment)
{
char **enviro;
if (items[1])
myprinter("leave arguments\n");
enviro = environ;
if (!enviro || !environ)
return (-1);
for ( ; *enviro; enviro++)
{
write(STDOUT_FILENO, *enviro, _strlen(*enviro));
write(STDOUT_FILENO, "\n", 1);
}
environment++;
return (0);
}
/**
  * _cd - function to change wd
  * @items: argument
  * Return: success
  */
int _cd(char **items)
{
char *gett;
char pwd[BUFSIZE];
char *back;
back = _getenv("HOME");
if (items[1])
{
if (items[1][0] == '~' && !items[1][1])
gett = back;
else if (items[1][0] == '-' && !items[1][1])
gett = _getenv("OLDPWD");
else
gett = items[1];
}
else
gett = back;
if (gett == back)
chdir(gett);
else if (access(gett, F_OK | R_OK) == 0)
chdir(gett);
else
myprinter("Could not find directory\n");
setenv("OLDPWD", _getenv("PWD"), 1);
setenv("PWD", getcwd(pwd, sizeof(pwd)), 1);
return (0);
}

