#include "monty.h"

/**
 * mod - computes the modulus of TOS1 by TOS
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number contaning the sub command
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_no)
{
	int n, data, data1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(stack, line_no);
	if (data == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}

	data1 = pop(stack, line_no);
	n = data1 % data;
	push(stack, line_no, n);
}
