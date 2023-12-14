#include "shell.h"
/**
  * _getenv - function to get environment
  * @tag: the string
  * Return: val of the key
  */
char *_getenv(const char *tag)
{
	int start, dodge, length;
	char **env, *tempo;

	if (!tag)
		return (NULL);
	env = environ;
	for (start = 0; env[start]; start++)
	{
		for (length = 0; env[start][length] != '='; length++)
			;
		length++;
		tempo = malloc((length) * sizeof(char));
		_memcpy(tempo, env[start], length - 1);
		tempo[length - 1] = '\0';
		if (_strncmp((char *)tag, tempo, _strlength(tempo)) == 0)
		{
			free(tempo);
			tempo = NULL;
			for (dodge = 0; env[start][dodge]; dodge++)
			{
				if (env[start][dodge] == '=')
				{
					tempo = &env[start][dodge + 1];
					break;
				}
			}
			return (tempo);
		}
		free(tempo);
		tempo = NULL;
	}
	return (NULL);
}
/**
  * _unsetenv - function to deletes val.
  * @tag: key=val pair
  * Return: Success or failure
  */
int _unsetenv(const char *tag)
{
	return (unsetenv(tag));
}
/**
  * _setenv - function to add val.
  * @tag: tag of key=val pair
  * @val: value
  * @turn: flag
  * Return: 0 on success or -1 on failure
  */
int _setenv(const char *tag, const char *val, int turn)
{
	return (setenv(tag, val, turn));
}
