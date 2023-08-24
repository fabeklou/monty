#include "monty.h"

/* global variable <essential> make available in this file */
trackg_t essential;

/**
 * push_opcode - pushes an element to the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int verdict;
	(void)line_number;

	verdict = stack_push(stack, essential.data);

	if (!verdict)
		return;

	dprintf(STDERR_FILENO, "Error: malloc failed\n");
	fclose(essential.fp);
	stack_free_all(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pall_opcode -  prints all the values on the stack, starting
 * from the top of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack_is_empty(stack))
		return;

	stack_display(*stack);
}