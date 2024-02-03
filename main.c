#include "monty.h"
<<<<<<< HEAD
int value;

/**
 * main - main function
 * @argc: number of argument
 * @argv: array of argument
 *
 * Return: 0 or exit
=======
#include <stdio.h>
#include <stdlib.h>

char **op_toks = NULL;

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
>>>>>>> 8d356dab350e21a6e9892c90c748ca3ccaec3144
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

	return EXIT_SUCCESS;
}
