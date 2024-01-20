#include "monty.h"

/**
 * atoi_and_push - parses a string to an integer
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number containing push command
 * @str: The string to parse
 *
 * Return: void
 */
void atoi_and_push(stack_t **stack, unsigned int line_no, char *str)
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

	push(stack, line_no, (int)n);
}

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

/**
 * free_stack - Frees memory alloc'd to stack
 * @stack: Pointer to a pointer to the first element of the stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
