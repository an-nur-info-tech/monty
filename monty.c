#include "monty.h"
int StackQueue = 1;

/**
 * main - main function for the monty
 * @argc: argument count
 * @argv: array of argument strings
 * Return: exit code
 */
int main(int argc, char **argv)
{
	FILE *file_in;
	unsigned int l_num = 0;
	char line[MAX_LINE_LENGTH];
	stack_t *top = NULL;
	instruction_t *instrctn = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file_in) != NULL)
	{
		l_num++;
		instrctn = parse_line(line);
		if (!(instrctn->opcode) || instrctn->opcode[0] == '#')
		{
			free(instrctn);
			continue;
		}
		if (instrctn->f)
			instrctn->f(&top, l_num);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, instrctn->opcode);
			if (top)
				free(top);
			free(instrctn), fclose(file_in);
			exit(EXIT_FAILURE);
		}
		free(instrctn);
	}
	free_stck(top),	fclose(file_in);
	return (0);
}
