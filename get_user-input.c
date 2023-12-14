#include "gshell.h"

/**
* get_user_input - Prompt user for input and read the input.
*
* This function prompts the user for input, reads the input line,
* removes the newline character, and returns the dynamically allocated string.
*
* Return: A dynamically allocated string containing user input.
* NULL if an error occurs or Ctrl+D is pressed.
*/
char *get_user_input(void)
{
	char *lineptr = NULL;

	size_t n = 0;
	ssize_t n_read;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	fflush(stdout);

	n_read = getline(&lineptr, &n, stdin);

	if (n_read == -1)
	{
		free(lineptr);
		lineptr = NULL;
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(0);
	}

	lineptr[n_read - 1] = '\0';

	return (lineptr);
}
