#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

/**
 * execute - Execute Monty bytecode instructions
 * @opcode: Opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
