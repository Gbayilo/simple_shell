#ifndef GSHELL_H
#define GSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

char *get_user_input(void);
char **parse_input(char *input);
char **tokenize(char *str, const char *delim);
void get_cmd_path(char **command);
void free_cmds(char **cmds);
int execute_command(const char *shell_name, size_t cmd_count, char **commands);

#endif
