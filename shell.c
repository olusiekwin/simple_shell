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

    while (1)
    {
        printf("\033[1;32mGraham@~$ \033[0m");
        fflush(stdout);

        command = getline_custom();

        if (command == NULL)
        {
            printf("\n");
            break;
        }

        handle_builtin_commands(command, &exit_code);

        if (exit_code)
            break;

        execute_command(command);

        free(command);
    }

    return exit_code;
}
