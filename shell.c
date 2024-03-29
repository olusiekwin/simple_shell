#include "shell.h"

/**
* main - Entry point of the shell
*
* Return: Exit status of the shell
*/
int main(void)
{
char *command;
int exit_code = 0;
int interactive_mode = isatty(STDIN_FILENO);

while (1)
{
if (interactive_mode)
printf("\033[1;32mGraham@~$ \033[0m");
fflush(stdout);

command = getline_custom();

if (command == NULL)
{
if (interactive_mode)
printf("\n");
break;
}

handle_builtin_commands(command, &exit_code);

if (!exit_code)
break;

execute_command(command, &exit_code);

free(command);
}

return exit_code;
}
 