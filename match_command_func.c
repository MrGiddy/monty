#include "monty.h"

/**
 * match_command - matches command with appropriate function
 * @argv: An array of strings (command and argument) passed
 * @line_no: The line number of command being processed
 *
 * Return: void
 */
void match_command(char **argv, int line_no)
{
	if (strcmp(argv[0], "push") == 0)
	{
		push(atoi(argv[1]));
	}
	else if (strcmp(argv[0], "pall") == 0)
	{
		pall();
	}
	else
	{
		dprintf(2, "%s%d%s %s\n", "L", line_no, ": unknown instruction", argv[0]);
		exit(EXIT_FAILURE);
	}
}
