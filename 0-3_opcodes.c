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
 * pall_opcode - prints all the values on the stack, starting
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

/**
 * pint_opcode - prints the value at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack_is_empty(stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", essential.line_num);
		fclose(essential.fp);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack_top(stack));
}

/**
 * pop_opcode - removes the top element of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack_is_empty(stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", essential.line_num);
		fclose(essential.fp);
		exit(EXIT_FAILURE);
	}

	printf("\tI am about to pop ! and size is : %d \n", essential.stack_size);
	stack_pop(stack);
}

/**
 * swap_opcode - swaps the top two elements of the stack
 *
 * @stack: pointer to the pointer to the top most element/node
 *			of the stack
 * @line_number: line number of the executing opcode
 *
 * Return: nothing
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;
	(void)line_number;

	if (essential.stack_size < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", essential.line_num);
		fclose(essential.fp);
		stack_free_all(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
