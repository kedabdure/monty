#include "monty.h"
/**
 * execute - Executes a Monty instruction.
 * @line: The instruction to execute.
 * @head: Pointer to the head of the stack.
 * @line_num: Line number of the instruction.
 */
void execute(char *line, stack_t **head, unsigned int line_num)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{NULL, NULL}
	};
	instruction_t *current_instruction = NULL;

	current_instruction = NULL;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, line) == 0)
		{
			current_instruction = &instructions[i];
			break;
		}
	}
	if (current_instruction == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, line);
		exit(EXIT_FAILURE);
	}
	current_instruction->f(head, line_num);
}
