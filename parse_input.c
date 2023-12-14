#include "gshell.h"

/**
 * parse_input - Tokenize user input into an array of commands.
 *
 * This function takes a user input string, tokenizes it based on space,
 * and returns a dynamically allocated array of strings representing commands.
 *
 * @input: The user input string to be parsed.
 *
 * Return: A dynamically allocated array of strings (commands).
 *         NULL if an error occurs or no commands are found.
 */
char **parse_input(char *input)
{
	char **commands = tokenize(input, " ");

	return (commands);

}
