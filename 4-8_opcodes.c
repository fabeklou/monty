#include "monty.h"

/* global variable <essential> make available in this file */
trackg_t essential;

/**
 * add_opcode - adds the top two elements of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				line_number);
		fclose(essential.fp);
		if (essential.stack_size == 1)
			stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	stack_pop(stack);
	(*stack)->n += temp;
}

/**
 * nop_opcode - doesn’t do anything
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_opcode - subtracts the top element of the stack from the
 * second top element of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				line_number);
		fclose(essential.fp);
		if (essential.stack_size == 1)
			stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	stack_pop(stack);
	(*stack)->n -= temp;
}

/**
 * div_opcode - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
				line_number);
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
	(*stack)->n /= temp;
}

/**
 * mul_opcode - swaps the top two elements of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
				line_number);
		fclose(essential.fp);
		if (essential.stack_size == 1)
			stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	stack_pop(stack);
	(*stack)->n *= temp;
}
