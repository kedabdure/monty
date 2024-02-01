#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: argument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	readMontyFile(argv[1]);
	return (0);
}

