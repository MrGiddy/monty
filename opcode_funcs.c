#include "monty.h"

stack_t *top = NULL;

/**
 * push - pushes an element to the stack
 * @n: Data for tne node
 *
 * Description:
 * Pushes an element to the beginning of a doubly
 * linked list implementation of the stack
 * Return: void
 */
void push(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (top == NULL)
	{
		top = new_node;
	}
	else
	{
		top->prev = new_node;
		new_node->next = top;
		top = new_node;
	}
}

/**
 * pall - prints all values of the stack starting from tos
 *
 * Return: void
 */
void pall(void)
{
	stack_t *current;

	current = top;
	if (current == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - removes the top element of the stack
 * @line_no: The line containing pop command
 *
 * Return: The element popped
 */
int pop(int line_no)
{
	stack_t *current;
	int data;

	if (top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}

	current = top;
	data = current->n;

	if (top->next == NULL)
	{
		top = NULL;
	}
	else
	{
		top = top->next;
		top->prev = NULL;
	}

	free(current);
	return (data);
}

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
