#include "monty.h"

/**
 * readMontyFile - Reads a Monty bytecode file and executes the instructions
 * @file_name: The name of the Monty file to read
 *
 * This function reads instructions from a Monty bytecode file, processes them,
 * and executes the corresponding operations.
 */
void readMontyFile(char *file_name)
{
	char buffer[100];
	unsigned int line_num = 1;
	stack_t *head = NULL;
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		processIns(buffer, &head, line_num);
		line_num++;
	}

	fclose(file);
}

