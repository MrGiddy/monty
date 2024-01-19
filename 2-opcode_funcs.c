#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @line_no: The line number containing add opcode
 *
 * Return: void
 */
void add(int line_no)
{
	int n, data, data1;

	if (top == NULL || top->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(-1);
	data1 = pop(-1);
	n = data + data1;
	push(n);
}

/**
 * nop - doesn't do anything
 *
 * Return: void
 */
void nop(void)
{

}
