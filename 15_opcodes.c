#include "monty.h"

/* global variable <essential> make available in this file */
trackg_t essential;

/**
 * stack_opcode - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void stack_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	essential.mode = true;
}

/**
 * queue_opcode - sets the format of the data to a queue (FIFO)
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void queue_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	essential.mode = false;
}
