#include "gshell.h"

/**
 * get_cmd_path - gets the full path to a command if it's valid and exist in
 * the PATH list of directories
 * @command: a pointer to the string containing the command to get full path
 *
 */
void get_cmd_path(char **command)
{
	char *dir = NULL, *path = NULL, *path_dir, *dup_str;

	if (*command == NULL || command == NULL)
		return;

	path_dir = getenv("PATH");
	if (path_dir == NULL)
		return;

	dup_str = strdup(path_dir);
	dir = strtok(dup_str, ":");

	while (dir != NULL)
	{
		path = malloc(sizeof(char) * (strlen(*command) + strlen(dir) + 2));
		if (path == NULL)
		{
			fprintf(stderr, "Memory alloaction failed\n");
			return;
		}

		sprintf(path, "%s/%s", dir, *command);

		if (access(path, X_OK) == 0)
		{
			free(*command);
			*command = strdup(path);
			free(path);
			break;
		}

		free(path);
		dir = strtok(NULL, ":");
	}
	free(dup_str);

}

/**
 * free_cmds - handles the deallocation of the string array containing the
 * tokenized input string.
 * @cmds: the string array of commands to free. It is recommended to call this
 * function after each command execution
 */
void free_cmds(char **cmds)
{
	size_t i;

	for (i = 0; cmds[i] != NULL; i++)
	{
		free(cmds[i]);
		cmds[i] = NULL;
	}
	free(cmds);
}

/**
 * tokenize - returns a string array of strings based on a delimiter
 * @str: the string to tokenize
 * @delim: the delimiter
 *
 * Return: a NULL-terminated string array of words
 */
char **tokenize(char *str, const char *delim)
{
	char **commands = NULL, *token, *dup_str;
	size_t num_of_tokens, i;

	if (str == NULL || *str == '\0')
		return (NULL);
	dup_str = strdup(str);
	token = strtok(dup_str, delim);

	num_of_tokens = 0;
	while (token != NULL)
	{
		++num_of_tokens;
		token = strtok(NULL, delim);
	}
	free(dup_str);

	if (num_of_tokens > 0)
	{

		commands = malloc(sizeof(char *) * (num_of_tokens + 1));
		if (commands == NULL)
			exit(EXIT_FAILURE);

		token = strtok(str, delim);
		i = 0;
		while (token != NULL)
		{
			commands[i++] = strdup(token);
			token = strtok(NULL, delim);
		}
		commands[i] = NULL;
	}

	return (commands);
}
