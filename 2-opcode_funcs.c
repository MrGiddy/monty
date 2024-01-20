#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number containing add opcode
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_no)
{
	int n, data, data1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(stack, line_no);
	data1 = pop(stack, line_no);
	n = data + data1;
	push(stack, line_no, n);
}

/**
 * nop - doesn't do anything
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number containing nop opcode
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_no)
{
	UNUSED(stack);
	UNUSED(line_no);
}

/**
 * sub - subtracts top element from second top element of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number contaning the sub command
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_no)
{
	int n, data, data1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(stack, line_no);
	data1 = pop(stack, line_no);
	n = data1 - data;
	push(stack, line_no, n);
}

/**
 * divide - Implement the div opcode
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number containing the div opcode
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_no)
{
	int data, data1;
	float n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(stack, line_no);
	if (data == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}

	data1 = pop(stack, line_no);
	n = data1 / data;
	push(stack, line_no, (int)n);
}

/**
 * mul - Multiplies the second top element with the top eleent of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line number contaning the sub command
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_no)
{
	int n, data, data1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(stack, line_no);
	data1 = pop(stack, line_no);
	n = data1 * data;
	push(stack, line_no, n);
}
