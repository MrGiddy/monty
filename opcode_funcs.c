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
 * pint - prints the value at the top of the stack
 * @line_no: The line with the pint command
 *
 * Return: void
 */
void pint(int line_no)
{
	if (top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}

/**
 * swap - swaps the top two elements of the stack
 * @line_no: The line with the swap command
 *
 * Return: void
 */
void swap(int line_no)
{
	stack_t *first, *second;

	if (top == NULL || top->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	first = top;
	second = top->next;

	if (second->next != NULL)
		second->next->prev = first;

	first->next = second->next;
	second->prev = NULL;

	second->next = first;
	first->prev = second;
	top = second;
}

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
		dprintf(2, "L%d: can't add, stack too short", line_no);
		exit(EXIT_FAILURE);
	}

	data = pop(-1);
	data1 = pop(-1);
	n = data + data1;
	push(n);
}
