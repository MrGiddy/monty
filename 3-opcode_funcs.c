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

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: Pointer to a pointer to first node of a stack_t doubly linked list
 * @line_no: The line number containing the pchar opcode
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_no)
{
	int data;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}

	data = (*stack)->n;
	if (data < 0 || data > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", data);
}

/**
 * pstr - Prints the string starting at TOS
 * @stack: Pointer to  pointer to first node of a stack_t doubly linked list
 * @line_no: The line number containing the pstr opcode
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *current;

	UNUSED(line_no);

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		/* break if 0 is encountered */
		if (current->n == 0)
			break;

		/* break if ascii value is out of range */
		if (current->n < 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @stack: Pointer to a pointer to first node of a stack_t doubly linked list
 * @line_no: The line number containing the rotl opcode
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *temp, *temp2;

	UNUSED(line_no);

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	temp2->prev = NULL;
	*stack = temp2;
}
