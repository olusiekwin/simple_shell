#include "shell.h"

/**
* execute_command - Executes the command using execve
* @command: Command string
*
* Description: Splits the command into arguments and executes it using execve.
*/
void execute_command(char *command)
{
pid_t child_pid;
char *args[] = {"/bin/sh", "-c", NULL, NULL};

args[2] = command;

child_pid = fork();

if (child_pid == -1)
{
perror("\033[1;31mfork\033[0m");
return;
}
else if (child_pid == 0)
{
execute_command_and_print_output(args);
}
else
{
int status;
waitpid(child_pid, &status, 0);

if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
{
fprintf(stderr, "Command exited with status %d\n", WEXITSTATUS(status));
}
}
}

/**
* execute_command_and_print_output - Executes the command using execve and prints the output
* @args: Command arguments
*
* Description: Executes the command using execve and redirects the output
*              to the parent process for printing.
*/
void execute_command_and_print_output(char **args)
{
int pipefd[2];
if (pipe(pipefd) == -1)
{
perror("\033[1;31mpipe\033[0m");
exit(1);
}

dup2(pipefd[0], STDIN_FILENO);
close(pipefd[1]);

if (execve(args[0], args, NULL) == -1)
{
perror("\033[1;31mexecve\033[0m");
exit(1);
}
}
