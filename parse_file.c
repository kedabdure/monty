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
    ssize_t read;
    unsigned int line_number = 1;

    char *opcode, *arg;

    while ((read = getline(&line, &len, file)) != -1)
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
