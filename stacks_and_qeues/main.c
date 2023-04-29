#include "monty.h"

/**
 * main - main function, reads a file and executes the bytecode
 * @argv: the name of the file that contains the bytecode
 * @argc: the number of arguemnts in argv
 * Return: returns 0 on succes and 1 on failure
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *line = NULL;
	FILE *fp = NULL;
	char *opcode = NULL;
	int line_number = 0;
	size_t allocd_size;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
	while (getline(&line, &allocd_size, fp) != -1)
	{
		opcode = strtok(line, delims);
		line_number++;
		if (opcode)
			opcode_manager(&head, opcode, line_number);
	}
	free(line);
	return (0);
}
