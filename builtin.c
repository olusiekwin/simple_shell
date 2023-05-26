#include "shell.h"
#include <stdlib.h>

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
    else
    {
        char **args = malloc(4 * sizeof(char *));
        args[0] = "/bin/sh";
        args[1] = "-c";
        args[2] = command;
        args[3] = NULL;

        execute_command_and_print_output(args);

        free(args);
    }
}

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
                {
                    perror("setenv");
                }
            }
            else
            {
                if (setenv(arg, "", 1) == -1)
                {
                    perror("setenv");
                }
            }
        }
    }
}

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
