#include "monty.h"

/* global variable <essential> make available in this file */
trackg_t essential;

/**
 * mod_opcode - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		fclose(essential.fp);
		if (essential.stack_size == 1)
			stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	if (temp == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		fclose(essential.fp);
		stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	stack_pop(stack);
	(*stack)->n %= temp;
}

/**
 * pchar_opcode - prints the char at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack_is_empty(stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		fclose(essential.fp);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	if (temp < 0 || temp > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
				line_number);
		fclose(essential.fp);
		stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(temp);
	printf("\n");
}

/**
 * pstr_opcode - prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *st;
	(void)line_number;

	st = *stack;

	while (st)
	{
		if (st->n <= 0 || st->n > 127)
			break;
		putchar(st->n);
		st = st->prev;
	}
	printf("\n");
}

/**
 * rotl_opcode - rotates the stack to the top
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *st = *stack;
	(void)line_number;

	if (essential.stack_size < 2)
		return;

	st->next = essential.st_bottom;
	temp = st->prev;
	st->prev = NULL;
	*stack = temp;

	(*stack)->next = NULL;

	essential.st_top = temp;
	essential.st_bottom = st;
}

/**
 * rotr_opcode - rotates the stack to the bottom
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *st = essential.st_bottom;
	(void)line_number;

	if (essential.stack_size < 2)
		return;

	st->prev = (*stack);
	essential.st_bottom = st->next;
	st->next = NULL;
	essential.st_bottom->prev = NULL;

	essential.st_top = st;
	*stack = st;
}
