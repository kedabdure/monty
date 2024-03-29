#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void readMontyFile(char *filename);
void push(stack_t **head, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
void execute(char *line, stack_t **head, unsigned int line_num);
char *validate(char *instruction, unsigned int line_num);
int isnum(char *arg);
void free_st(stack_t *head);
void pint(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
#endif

