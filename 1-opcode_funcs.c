#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: Line number contiaing the pall command
 * @n: Data for tne node
 *
 * Description:
 * Pushes an element to the beginning of a doubly
 * linked list implementation of the stack
 * Return: void
 */
void push(stack_t **stack, unsigned int line_no, int n)
{
	stack_t *new_node, *temp;

	UNUSED(line_no);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "%s\n", "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		/* If stack mode: insert node at beginning */
		if (glob_mode == 0)
		{
			(*stack)->prev = new_node;
			new_node->next = *stack;
			*stack = new_node;
		}
		/* If queue mode, insert node at the end */
		else if (glob_mode == 1)
		{
			temp = *stack;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}

/**
 * pall - prints all values of the stack starting from tos
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: Line number contiaing the pall command
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *current;

	UNUSED(line_no);

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line containing pop command
 *
 * Return: The element popped
 */
int pop(stack_t **stack, unsigned int line_no)
{
	stack_t *current;
	int data;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	data = current->n;

	if ((*stack)->next == NULL)
	{
		(*stack) = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}

	free(current);
	return (data);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line with the pint command
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: Pointer to a pointer to the first element of the stack
 * @line_no: The line with the swap command
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *first, *second;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	if (second->next != NULL)
		second->next->prev = first;

	first->next = second->next;
	second->prev = NULL;

	second->next = first;
	first->prev = second;
	*stack = second;
}
