#include "monty.h"

stack_t *stack = NULL;

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
		if (line[0] == '\n' || line[0] == '\0' || is_empty_line(line))
			continue;
		av = parse_line(line);
		match_command(&stack, line_no, av);

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
