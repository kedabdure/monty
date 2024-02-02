#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
int value = 0;

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parse_monty(file, &stack);
	fclose(file);

	free_stack(stack);

	exit(EXIT_FAILURE);
}
