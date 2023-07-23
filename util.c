#include "shell.h"

/**
* split_commands - Splits the input into multiple commands based on the delimiter
* @input: The input string containing multiple commands
* @delimiter: The delimiter to use for splitting the commands
*
* Return: An array of strings containing the individual commands
*/
char **split_commands(char *input, const char *delimiter)
{
int bufsize = 64;
int position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc error");
exit(EXIT_FAILURE);
}

token = strtok(input, delimiter);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
perror("realloc error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, delimiter);
}
tokens[position] = NULL;
return tokens;
}

/**
* split_command - Splits the command into individual arguments
* @command: The command to split
*
* Return: An array of strings containing the individual arguments
*/
char **split_command(char *command)
{
int bufsize = 64;
int position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc error");
exit(EXIT_FAILURE);
}

token = strtok(command, " \t\n");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
perror("realloc error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n");
}
tokens[position] = NULL;
return tokens;
}

/**
* is_builtin_command - Checks if a command is a built-in shell command
* @command: The command to check
*
* Return: 1 if the command is built-in, 0 otherwise
*/
int is_builtin_command(char *command)
{
if (strcmp(command, "exit") == 0 || strcmp(command, "cd") == 0 ||
strcmp(command, "setenv") == 0 || strcmp(command, "unsetenv") == 0 ||
strcmp(command, "env") == 0)
{
return 1;
}
return 0;
}
