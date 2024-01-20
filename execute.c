#include "monty.h"

/**
 * match_command - matches command with appropriate function
 * @stack: Pointer to a pointer to the first node of stack_t doubly linked list
 * @line_no: The line number of the opcode instruction to be executed
 * @argv: An array of strings: argv[0] is opcode and argv[1] is argument
 *
 * Return: void
 */
void match_command(stack_t **stack, unsigned int line_no, char **argv)
{
	char *opcode;
	size_t i;

	instruction_t array[] = {
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL},
	}; /* prototype: void (*f)(stack_t **, int) */

	opcode = argv[0];

	if (strcmp(opcode, "push") == 0)
	{
		atoi_and_push(stack, line_no, argv[1]);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_no); /* prototype: int pop(stack_t, int) */
	}
	else
	{
		for (i = 0; array[i].opcode; i++)
		{
			if (strcmp(opcode, array[i].opcode) == 0)
			{
				array[i].f(stack, line_no);
				return;
			}
		}
		dprintf(2, "L%d: unknown instruction %s\n", line_no, opcode);
		exit(EXIT_FAILURE);
	}
}
