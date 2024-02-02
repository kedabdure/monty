#include "monty.h"

int value = 0;

/**
 * parse_monty - Parse Monty bytecode instructions
 * @file: Monty bytecode file
 * @stack: Pointer to the stack
 */
void parse_monty(FILE *file, stack_t **stack)
{
	char *line = NULL;
    	size_t len = 0;
    	unsigned int line_number = 1;

	char *arg, *opcode;

    while (fgets(line, len, file) != NULL)
    {
        opcode = strtok(line, " \t\n");
	    
        if (opcode == NULL || opcode[0] == '#')
        {
            line_number++;
            continue;
        }
        arg = strtok(NULL, " \t\n");

        if (arg != NULL)
        {
            value = atoi(arg);
        }

        execute(opcode, stack, line_number);

        line_number++;
    }

    free(line);
}
