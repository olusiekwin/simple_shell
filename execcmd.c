#include "shell.h"

/**
* execute_command - Executes the command using execvp
* @command: Command string
*
* Description: Splits the command into arguments and executes it using execvp.
*/
void execute_command(char *command)
{
pid_t child_pid;
char *args[4];
char *args_temp[] = {"/bin/sh", "-c", NULL, NULL};
args_temp[2] = command;

memcpy(args, args_temp, sizeof(args_temp));

child_pid = fork();

if (child_pid == (pid_t)-1)
{
perror("\033[1;31mfork\033[0m");
return;
}
else if (child_pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("\033[1;31mexecvp\033[0m");
exit(1);
}
}
else
{
int status;
waitpid(child_pid, &status, 0);
}
}
