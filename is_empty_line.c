#include "monty.h"

/**
 * is_empty_line - Checks if a line is empty
 * @line: Line to check
 *
 * Return: 1 if is empty 0 if not
 */
int is_empty_line(char *line)
{
	int i, is_empty;

	is_empty = 1;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (!isspace((unsigned char)line[i]))
		{
			is_empty = 0;
			break;
		}
	}

	return (is_empty);
}
