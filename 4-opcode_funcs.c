#include "monty.h"

/**
 * _stack - Switches to stack mode
 * @stack: Pointer to a pointer to first node of a stack_t doubly linked list
 * @line_no: The line number containing the stack opcode
 *
 * Description:  stack mode is glob_mode = 0
 *
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_no)
{
	UNUSED(stack);
	UNUSED(line_no);

	glob_mode = 0;
}

/**
 * queue - Switches to queue mode
 * @stack: Pointer to a pointer to first node of a stack_t doubly linked list
 * @line_no: The line number containing the queue opcode
 *
 * Description:  queue mode is glob_mode = 1
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_no)
{
	UNUSED(stack);
	UNUSED(line_no);

	glob_mode = 1;
}
