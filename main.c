#include "monty.h"
int value;

/**
 * main - main function
 * @argc: number of argument
 * @argv: array of argument
 *
 * Return: 0 or exit
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

