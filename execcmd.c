#include "shell.h"

/**
* execute_command_and_print_output - Executes the given command and
* prints its output
* @args: The command arguments
* @exit_code: Pointer to the exit code variable (for built-in commands)
*/
void execute_command_and_print_output(char **args, int *exit_code)
{
if (args[0] != NULL)
{
if (is_builtin_command(args[0]))
{
handle_builtin_commands(args[0], exit_code);
}
else
{
int pid, status;
int prev_status = 0; /* Previous command's exit status */
int exec_next = 1;   /* Flag to execute the next command */

while (*args != NULL)
{
if (exec_next)
{
pid = fork();

if (pid == 0)
{
/* Redirect stderr to stdout */
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

/* Check the exit status of the current command */
/* If it is 0 (success), set exec_next to 1 for the next command */
/* If it is non-zero (failure), set exec_next to 0 for the next command */
exec_next = (status == 0) ? 1 : 0;

/* If the previous command used "&&" and failed, break the loop */
if (prev_status == 0 && args[1] != NULL && strcmp(args[1], "&&") == 0 && exec_next == 0)
break;

/* If the previous command used "||" and succeeded, break the loop */
if (prev_status != 0 && args[1] != NULL && strcmp(args[1], "||") == 0 && exec_next == 1)
break;

prev_status = status;
args++; /* Move to the next command */
}
}
else
{
args++; /* Skip the current command */
if (*args != NULL)
{
args++; /* Skip the "&&" or "||" */
}
}
}
}
}
}
