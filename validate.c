#include "monty.h"

/**
 * validate - validate the instruction
 * @instruction: opcode
 * @line_num: number of line
 *
 * Return: opcode
 */
char *validate(char *instruction, unsigned int line_num)
{
	char *opc, *arg;

	opc = strtok(instruction, "\n; ");
	if (opc == NULL)
		return (NULL);

	if (strcmp(opc, "push") == 0)
	{
		arg = strtok(NULL, "\n; ");
		if (isnum(arg) == 1 && arg != NULL)
		{
			value = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (opc);
}

/**
 * isnum - check whether argument is a number or not
 * @arg: argument
 *
 * Return: 1 or 0
 */
int isnum(char *arg)
{
	unsigned int i = 0;

	if (arg == NULL)
		return (0);
	while (arg[i])
	{
		if (arg[i] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(arg[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
