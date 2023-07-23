#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
char *getline_custom(void);
char **split_commands(char *input, const char *delimiter);
char **split_command(char *command);
void execute_command(char *command, int *exit_code);
void execute_command_and_print_output(char **args, int *exit_code);
void handle_builtin_commands(char *command, int *exit_code);
void handle_exit_command(char *command, int *exit_code);
void handle_cd_command(char *command);
void handle_setenv_command(char *command);
void handle_unsetenv_command(char *command);
void print_environment(void);
int is_builtin_command(char *command);

#endif /* SHELL_H */
