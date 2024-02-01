#include "monty.h"
int value = 0;
/**
 * processIns - process the Monty instruction
 * @instruction: instruction to process
 * @head: double pointer to the head of the stack
 * @line_num: line number of the instruction
 *
 * Return: void
 */

void processIns(char *instruction, stack_t **head, unsigned int line_num)
{
	char *token;
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	instruction_t *current_instruction = NULL;

	token = strtok(instruction, " ");
	current_instruction = NULL;
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			current_instruction = &instructions[i];
			break;
		}
	}
	if (current_instruction == NULL)
	{
		fprintf(stderr, "L%u: Unknown instruction: %s\n", line_num, token);
		exit(EXIT_FAILURE);
	}
	if (strcmp(current_instruction->opcode, "push") == 0)
	{
		token = strtok(NULL, " ");
		if (token == NULL)
		{
			fprintf(stderr, "L%u: Missing value for push\n", line_num);
			exit(EXIT_FAILURE);
		}
		else
		{
			value = atoi(token);
		}
	}
	current_instruction->f(head, line_num);
}

