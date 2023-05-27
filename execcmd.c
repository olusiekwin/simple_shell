#include "shell.h"

/**
* execute_command - Executes the given command
* @command: The command to execute
*/
void execute_command(char *command)
{
handle_builtin_commands(command, NULL);
}

/**
* execute_command_and_print_output - Executes the given command and
* prints its output
* @args: The command arguments
*/
void execute_command_and_print_output(char **args)
{
pid_t pid;
int status;

pid = fork();

if (pid == 0)
{
/* Redirect stderr to stdout */
dup2(1, 2);

execvp(args[0], args);

/* If execvp fails, print the error message */
perror(args[0]);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else
{
wait(&status);
}
}
