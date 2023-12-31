#ifndef MONTY_H
#define MONTY_H

/* standard library functions */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *				for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *				for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct trackg_s - gather the top and the bottom (extremities)
 * of our stack, as well as the file pointer and the line number into
 * a single struct
 *
 * @fp: pointer to the bytecode file opened in memory
 * @line_num: number of the current line treated in the bytecode file
 * @data: data to be pushed in the stack
 * @stack_size: number of element/node in the stack
 * @mode: is the mode/structure in which the data is stored. his value is set
 *			to stack (true) by default, but can be set to queue (false)
 * @st_top: pointer to the top of the stack
 * @st_bottom: pointer to the bottom of the stack
 *
 * Description: keep track of a bunch of data, to make them avaible
 *				anywhere in the program
 */
typedef struct trackg_s
{
	FILE *fp;
	unsigned int line_num;
	int data;
	unsigned int stack_size;
	bool mode;
	stack_t *st_top;
	stack_t *st_bottom;
} trackg_t;

/* Making the struct trackg_s a global variable */
extern trackg_t essential;

/* stack functions */
int stack_push(stack_t **st, int data);
void stack_pop(stack_t **st);
bool stack_is_empty(stack_t **st);
int stack_top(stack_t **st);
void stack_free_all(stack_t *st);
void stack_display(stack_t *st);

/* queue functions */
int en_queue(stack_t **st, int data);

/* opcode functions */
void pall_opcode(stack_t **stack, unsigned int line_number);
void push_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);
void rotr_opcode(stack_t **stack, unsigned int line_number);
void stack_opcode(stack_t **stack, unsigned int line_number);
void queue_opcode(stack_t **stack, unsigned int line_number);

/* opcode utils */
bool _strcmp(char *s1, char *s2);
bool _is_valid_int(char *str);
bool check_lastchar(char *str);

/* execution functions */
void read_tok_run(FILE *fp);
void opcode_handler(char *opcode);

#endif /* end of MONTY_H */
