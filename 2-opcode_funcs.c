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

/**
 * sub - subtracts top element from second top element of the stack
 * @line_no: The line number contaning the sub command
 *
 * Return: void
 */
void sub(int line_no)
{
	int n, data, data1;

	if (top == NULL || top->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(-1);
	data1 = pop(-1);
	n = data1 - data;
	push(n);
}

/**
 * div - Implement the div opcode
 * @line_no: The line number containing the div command
 *
 * Return: void
 */
void divide(int line_no)
{
	int data, data1;
	float n;

	if (top == NULL || top->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(-1);
	if (data == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
		
	data1 = pop(-1);
	n = data1 / data;
	push((int)n);
}
