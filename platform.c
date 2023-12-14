#define COM_MAX_LEN 60

#include "shell.h"
/**
 * main - main entry point
 * pid_t: the child process
 *
 * Description: The variables
 * used in my shell program
 * Return: 0
 **/
int main(void)
{

char command[COM_MAX_LEN];

pid_t sub_id;

int condition;

while (true)
{
showPrompt();
read_input(char *command, COM_MAX_LEN)
run_command(command)
}

return (0);
}

