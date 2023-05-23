#include "shell.h"

/**
 * handle_builtin_commands - Handles the builtin commands
 * @command: Command string
 * @exit_code: Pointer to the exit code variable
 *
 * Description: Handles various builtins like exit,cd,setenv&unsetenv.
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
 * Description: Sets the exit code to 1 to exit the shell.
 */
void handle_exit_command(char *command, int *exit_code)
{
    if (strcmp(command, "exit") == 0)
    {
        *exit_code = 1;
    }
}

/**
 * handle_cd_command - Handles the cd command
 * @command: Command string
 *
 * Description: Changes the current working directory.
 */
void handle_cd_command(char *command)
{
    char *dir = strtok(command, " ");
    dir = strtok(NULL, " ");

    if (dir != NULL)
    {
        if (chdir(dir) != 0)
        {
            perror("\033[1;31mchdir\033[0m");
        }
    }
    else
    {
        printf("\033[1;31mInvalid argument for cd\033[0m\n");
    }
}

/**
 * handle_setenv_command - Handles the setenv command
 * @command: Command string
 *
 * Description: Sets the value of an environment variable.
 */
void handle_setenv_command(__attribute__((unused)) char *command)
{
    char *name, *value;
    name = strtok(NULL, " ");
    value = strtok(NULL, " ");

    if (name != NULL && value != NULL)
    {
        if (setenv(name, value, 1) != 0)
        {
            perror("\033[1;31msetenv\033[0m");
        }
    }
    else
    {
        printf("\033[1;31mInvalid arguments for setenv\033[0m\n");
    }
}

/**
 * handle_unsetenv_command - Handles the unsetenv command
 * @command: Command string
 *
 * Description: Unsets an environment variable.
 */
void handle_unsetenv_command(__attribute__((unused)) char *command)
{
    char *name = strtok(NULL, " ");

    if (name != NULL)
    {
        if (unsetenv(name) != 0)
        {
            perror("\033[1;31munsetenv\033[0m");
        }
    }
    else
    {
        printf("\033[1;31mInvalid argument for unsetenv\033[0m\n");
    }
}
