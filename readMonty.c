#include "monty.h"

/**
 * readMontyFile - Reads and processes Monty instructions from a file.
 * @file_name: The name of the Monty bytecode file.
 */
void readMontyFile(char *file_name)
{
        char *line;
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
                line = validate(buffer, line_num);
                if (line == NULL || line[0] == '#')
                {
                        line_num++;
                        continue;
                }

                execute(line, &head, line_num);
                line_num++;
        }
        fclose(file);
        free_st(head);
}
