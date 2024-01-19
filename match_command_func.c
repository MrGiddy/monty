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
		atoi_and_push(argv[1], line_no);
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
	else if (strcmp(argv[0], "add") == 0)
	{
		add(line_no);
	}
	else if (strcmp(argv[0], "nop") == 0)
	{
		nop();
	}
	else
	{
		dprintf(2, "L%d: unknown instruction %s\n", line_no, argv[0]);
		exit(EXIT_FAILURE);
	}
}

/**
 * atoi_and_push - parses a string to an integer
 * @str: The string to parse
 *
 * Return: void
 */
void atoi_and_push(char *str, int line_no)
{
	char *endptr;
	long int n;

	/* If string is NULL or invalid input. NB: Comma operator used */
	if (str == NULL || (strtol(str, &endptr, 10), *endptr != '\0'))
	{
		dprintf(2, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}

	errno = 0;
	n = strtol(str, &endptr, 10);

	/* If n overflows */
	if ((n == LONG_MIN || n == LONG_MAX) && errno == ERANGE)
	{
		dprintf(2, "L%d: integer overflow/underflow\n", line_no);
		exit(EXIT_FAILURE);
	}

	/* if n is outside range of int */
	if (n < INT_MIN || n > INT_MAX)
	{
		dprintf(2, "L%d: integer out of range for int\n", line_no);
		exit(EXIT_FAILURE);
	}

	push((int)n);
}
