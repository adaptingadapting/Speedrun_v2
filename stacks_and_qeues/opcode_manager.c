#include "monty.h"

/**
 * opcode_manager - executes the opcode or returns an error
 * @stack: the stack to execute the function on
 * @code: opcode, instructions on what to do
 * @line_number: the line number in case of error
 */

void opcode_manager(stack_t **stack, char *code, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
	  {"push", push},
	  {"pall", pall},
	  {"pint", pint},
	  {"pop", pop},
	  {"swap", swap},
	  {"add", add},
	  {"nop", nop},
	  {NULL, NULL}
	};
	for (i = 0; instructions[i].opcode; i++)
	{
		if (!(strcmp(instructions[i].opcode, code)))
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	if (code && code[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, code);
		exit(1);
	}
}
