#include "gshell.h"

/**
* main - entry point for the shell program
* @argc: arguments count (unused)
* @argv: arguments vector
*
* Return: 0 always on success.
*/
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *lineptr = NULL;

	char **commands = NULL;

	size_t cmd_count = 0;

	while (1)
	{
		lineptr = get_user_input();
		++cmd_count;

		if (*lineptr == '\0')
			continue;

		commands = parse_input(lineptr);
		if (commands == NULL)
			continue;

		if (execute_command(argv[0], cmd_count, commands) == -1)
			continue;

		free(lineptr);
		free_cmds(commands);
		commands = NULL;
		lineptr = NULL;
	}
	return (0);
}
