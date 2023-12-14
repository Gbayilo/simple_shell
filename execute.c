#include "gshell.h"

/**
* execute_command - Execute a command in a child process.
* @shell_name: the name of the shell program
* @cmd_count: the count of the current command
* @commands: the array of command and arguments
*
* Return: 0 on success, -1 on failure.
*/
int execute_command(const char *shell_name, size_t cmd_count, char **commands)
{
	pid_t child;
	int status;

	if (access(commands[0], X_OK) == -1)
	{
		get_cmd_path(&commands[0]);
		if (commands != NULL && access(commands[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: %lu: %s: not found\n",
					shell_name, cmd_count, commands[0]);

			free_cmds(commands);
			return (-1);
		}
	}

	child = fork();
	if (child == -1)
		return (-1);

	if (child == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
			perror("execve");
	}
	else
	{
		waitpid(child, &status, 0);
	}

	return (0);
}
