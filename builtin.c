#include "shell.h"

/**
* handle_builtin_commands - Handles the execution of built-in commands
* @command: The command to handle
* @exit_code: Pointer to the exit code variable
*/
void handle_builtin_commands(char *command, int *exit_code)
{
if (strncmp(command, "exit", 4) == 0)
{
handle_exit_command(command, exit_code);
}
else if (strncmp(command, "cd", 2) == 0)
{
handle_cd_command(command);
}
else if (strncmp(command, "setenv", 6) == 0)
{
handle_setenv_command(command);
}
else if (strncmp(command, "unsetenv", 8) == 0)
{
handle_unsetenv_command(command);
}
else if (strncmp(command, "env", 3) == 0)
{
print_environment();
}
else
{
char **args = split_command(command);
execute_command_and_print_output(args, exit_code);
free(args);
}
}

/**
* handle_exit_command - Handles the "exit" command
* @command: The exit command to handle
* @exit_code: Pointer to the exit code variable
*/
void handle_exit_command(char *command, int *exit_code)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
{
*exit_code = atoi(arg); /* Convert the argument to an integer */
}
else
{
*exit_code = 0; /* Default exit status is 0 if no argument is provided */
}
}

exit(*exit_code);
}

/**
* handle_cd_command - Handles the "cd" command
* @command: The cd command to handle
*/
void handle_cd_command(char *command)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
{
if (chdir(arg) == -1)
{
perror("cd");
}
}
else
{
const char *home_dir = getenv("HOME");
if (home_dir != NULL)
{
if (chdir(home_dir) == -1)
{
perror("cd");
}
}
}
}
}

/**
* handle_setenv_command - Handles the "setenv" command
* @command: The setenv command to handle
*/
void handle_setenv_command(char *command)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
{
char *value = strtok(NULL, "\n");
if (value != NULL)
{
if (setenv(arg, value, 1) == -1)
perror("setenv");
}
else
{
if (setenv(arg, "", 1) == -1)
perror("setenv");
}
}
}
}

/**
* handle_unsetenv_command - Handles the "unsetenv" command
* @command: The unsetenv command to handle
*/
void handle_unsetenv_command(char *command)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
{
if (unsetenv(arg) == -1)
perror("unsetenv");
}
}
}

/**
* print_environment - Prints the current environment variables
*/
void print_environment(void)
{
extern char **environ;
char **env = environ;

while (*env)
{
printf("%s\n", *env);
env++;
}
}
