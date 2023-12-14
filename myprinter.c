#include "shell.h"
/**
 * myprinter - Function for printing to
 * the standard output
 *
 *
 *
 */
void myprinter(const char *language)
/**
 * @language: string to print
 *
 * Description: @language representing the string
 * to print
 * Return 0;
 **/
{
write(STDOUT_FILENO, language, strlen(language));
}
