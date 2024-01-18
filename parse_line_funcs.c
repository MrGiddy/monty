#include "monty.h"

/**
 * parse_line - Parses a line from a file
 * @line: The line to parse
 *
 * Return: A pointer to an array of strings from parsed line
 */
char **parse_line(const char *line)
{
	char *line2, *tok;
	char **argv;
	int i;

	argv = malloc(sizeof(char *) * (count_string_tokens(line) + 1));
	if (argv == NULL)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line2 = strdup(line);
	if (line2 == NULL)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line2, " \t\n");
	for (i = 0; tok != NULL; i++)
	{
		argv[i] = strdup(tok);
		if (argv[i] == NULL)
		{
			free_argv(argv, i);
			dprintf(2, "%s\n", "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		tok = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	free(line2);
	return (argv);
}

/**
 * free_argv - Free array of strings if malloc fails
 * @argv: Argument vector
 * @i: Index of argv element at point of malloc failure
 *
 * Return: void
 */
void free_argv(char **argv, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		free(argv[j]);
	}
	free(argv);
}

/**
 * count_string_tokens - Counts the number of tokens in a string
 * @line: A string (the line tokenized)
 *
 * Return: Number of string tokens
 */
int count_string_tokens(const char *line)
{
	int tok_count;
	char *tok, *line2;

	line2 = strdup(line);
	if (line2 == NULL)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	tok_count = 0;
	tok = strtok(line2, " \t\n");
	while (tok != NULL)
	{
		tok_count++;
		tok = strtok(NULL, " \t\n");
	}
	free(line2);

	return (tok_count);
}
