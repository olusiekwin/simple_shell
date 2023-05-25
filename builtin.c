#include "shell.h"

/**
* handle_builtin_commands - Handles the builtin commands
* @command: Command string
* @exit_code: Pointer to the exit code variable
*
* Description: Handles various builtins like exit, cd, setenv, and unsetenv.
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
}

/**
* handle_exit_command - Handles the exit command
* @command: Command string
* @exit_code: Pointer to the exit code variable
*
* Description: Sets the exit code to the specified value or 0 if no value is
*              provided. Exits the shell with the given exit code.
*/
void handle_exit_command(char *command, int *exit_code)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
*exit_code = atoi(arg);
}

printf("\n");
exit(*exit_code);
}

/**
* handle_cd_command - Handles the cd command
* @command: Command string
*
* Description: Changes the current working directory to the specified path.
*              If no path is provided, changes the dir to the home dir.
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
* handle_setenv_command - Handles the setenv command
* @command: Command string
*
* Description: Sets the environment variable to the specified value. If the
*              variable does not exist, it is created.
*/
void handle_setenv_command(char *command)
{
char *arg = strtok(command, " \t\n");

if (arg != NULL)
{
arg = strtok(NULL, " \t\n");
if (arg != NULL)
{
char *value = strtok(NULL, " \t\n");
if (value != NULL)
{
if (setenv(arg, value, 1) == -1)
{
perror("setenv");
}
}
}
}
}

/**
* handle_unsetenv_command - Handles the unsetenv command
* @command: Command string
*
* Description: Unsets the specified environment variable.
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
{
perror("unsetenv");
}
}
}
}
