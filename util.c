#include "shell.h"

/**
* getline_custom - Reads a line of input from stdin
*
* Return: Pointer to the line read (including newline character)
*         or NULL if EOF is reached
*/
char *getline_custom(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t n;

n = getline(&line, &bufsize, stdin);

if (n == -1)
{
if (feof(stdin))
{
return (NULL);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}

return (line);
}

/**
* isatty - Check if a file descriptor refers to a terminal
* @fd: The file descriptor to check
*
* Return: 1 if the file descriptor refers to a terminal, 0 otherwise
*/
int isatty(int fd)
{
return (ttyname(fd) != NULL);
}
