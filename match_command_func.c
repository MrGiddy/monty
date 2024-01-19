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
		if (argv[1] == NULL || (argv[1][0] != '\0' && !isdigit(argv[1][0])))
		{
			dprintf(2, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
		push(atoi(argv[1]));
	}
	else if (strcmp(argv[0], "pall") == 0)
	{
		pall();
	}
	else if (strcmp(argv[0], "pop") == 0)
	{
		pop(line_no);
	}
	else if (strcmp(argv[0], "pint") == 0)
	{
		pint(line_no);
	}
	else if (strcmp(argv[0], "swap") == 0)
	{
		swap(line_no);
	}
	else
	{
		dprintf(2, "L%d: unknown instruction %s\n", line_no, argv[0]);
		exit(EXIT_FAILURE);
	}
}
