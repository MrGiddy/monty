#include "monty.h"

size_t glob_mode;

/**
 * init_stack - initializes stack in stack mode
 * @stack: Pointer to a pointer to first node of a stack_t doubly linked list
 *
 * Description: glob_mode: 0: stack mode, 1: queue mode
 *
 * Return: void
 */
void init_stack(stack_t **stack)
{
	*stack = NULL;
	glob_mode = 0;
}

/**
 * main - Check the code
 * @ac: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int ac, char **argv)
{
	FILE *file;
	char line[128];
	char **av;
	int line_no;
	int i;

	stack_t *stack;

	init_stack(&stack);
	if (ac == 1 || ac > 2)
	{
		dprintf(2, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_no = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_no++;
		if (line[0] == '\0' || is_empty(line) || if_comment(line))
			continue;
		av = parse_line(line);
		match_opcode(&stack, line_no, av);

		for (i = 0; av[i] != NULL; i++)
		{
			free(av[i]);
		}
		free(av);
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
