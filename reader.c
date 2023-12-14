#define COM_MAX_LEN 60

#include "shell.h"

/**
 * read_input - Function tontake user input
 *
 * @command: the input
 * @COM_MAX_LEN: constant for input length
 **/

void read_input(char *command, COM_MAX_LEN)
{
if (fgets(command, COM_MAX_LEN, stdin) == NULL)
{
if (feof(stdin))
{
myprinter("\n");
exit(EXIT_SUCCESS);
}
else
{
myprinter("My Shell has now stopped working. Come again later!\n");
exit(EXIT_FAILURE);
}
}

size_t com_len = strlen(command);
}

