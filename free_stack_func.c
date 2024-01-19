#include "monty.h"

/**
 * free_stack - Frees memory alloc'd to stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *current;

	while (top != NULL)
	{
		current = top;
		top = top->next;
		free(current);
	}
}
