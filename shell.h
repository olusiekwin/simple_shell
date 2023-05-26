#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

char *getline_custom(void);
void execute_command(char *command);
void handle_builtin_commands(char *command, int *exit_code);
void handle_exit_command(char *command, int *exit_code);
void handle_cd_command(char *command);
void handle_setenv_command(char *command);
void handle_unsetenv_command(char *command);
void execute_command_and_print_output(char **args);
void handle_ls_command(void);

#endif /* SHELL_H */
