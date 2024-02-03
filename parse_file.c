#include "monty.h"

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

    while (getline(&line, &len, file) != -1)
    {
        tokenize_line(line);

        if (op_toks_count > 0)
        {
            execute(op_toks[0], stack, line_number);

            // Free memory allocated for tokens
            for (int i = 0; i < op_toks_count; i++)
            {
                free(op_toks[i]);
            }
            free(op_toks);
        }

        line_number++;
    }

    free(line);
}

/**
 * tokenize_line - Tokenize a line and store tokens in op_toks
 * @line: Line to tokenize
 */
void tokenize_line(char *line)
{
    char *token;
    int token_count = 0;

    // Allocate memory for op_toks
    op_toks = (char **)malloc(MAX_TOKENS * sizeof(char *));
    if (op_toks == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for op_toks\n");
        exit(EXIT_FAILURE);
    }

    // Tokenize the line
    token = strtok(line, " \t\n");
    while (token != NULL && token_count < MAX_TOKENS)
    {
        // Allocate memory for each token
        op_toks[token_count] = strdup(token);
        if (op_toks[token_count] == NULL)
        {
            fprintf(stderr, "Error: Unable to allocate memory for token\n");
            exit(EXIT_FAILURE);
        }

        // Update token count and get the next token
        token_count++;
        token = strtok(NULL, " \t\n");
    }

    // Update the count of tokenized lines
    op_toks_count = token_count;
}
