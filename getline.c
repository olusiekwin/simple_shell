#include "shell.h"

/**
* getline_custom - Custom implementation of getline().
*
* Return: A pointer to the read line or NULL if error occurs or end of file is reached.
*/
char *getline_custom(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t chars_read = getline(&line, &bufsize, stdin);

if (chars_read == -1)
{
free(line);
return NULL;
}

if (chars_read > 0 && line[chars_read - 1] == '\n')
line[chars_read - 1] = '\0';

return line;
}
