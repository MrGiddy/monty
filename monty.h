#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define UNUSED(x) (void)x

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queu)
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

extern stack_t *stack;

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

/* parse_line_funcs.c */
char **parse_line(const char *line);
int count_string_tokens(const char *line);
void free_failed_argv(char **argv, int i);

/* match_command_func.c */
void match_command(stack_t **stack, unsigned int line_no, char **argv);

/* helper_funcs.c */
void free_stack(stack_t **stack);
void atoi_and_push(stack_t **stack, unsigned int line_no, char *str);
int is_empty(char *line);
int if_comment(char *line);

/* 1-opcode_funcs.c */
void push(stack_t **stack, unsigned int line_no, int n);
void pall(stack_t **stack, unsigned int line_no);
int pop(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);

/* 2-opcode_funcs.c */
void add(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void divide(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);

/* 3-opcode_funcs.c */
void mod(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);

#endif /* MONTY_H */
