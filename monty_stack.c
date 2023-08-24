#include "monty.h"

/* global variable make available in this file */
trackg_t essential;

/**
 * stack_push - adds an element to the top of the stack
 *
 * @st: pointer to the pointer to the top most element/node
 *      of the stack
 * @data: the data/element to be added
 *
 * Return: 1 representing failure, if malloc fail, 0 otherwise
 */
int stack_push(stack_t **st, int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		return (1);

	node->n = data;
	node->next = NULL;
	node->prev = (*st);
	if (*st)
		(*st)->next = node;

	essential.stack_size++;
	essential.st_top = node;

	if (essential.stack_size == 1)
		essential.st_bottom = node;

	return (0);
}

/**
 * stack_pop - removes the topmost element from the stack
 *
 * @st: pointer to the pointer to the top most element/node
 *      of the stack
 *
 * Return: nothing
 */
void stack_pop(stack_t **st)
{
	stack_t *temp;

	temp = (*st)->prev;
	temp->next = NULL;
	free(*st);

	essential.stack_size--;
	essential.st_top = temp;

	if (essential.stack_size == 0)
		essential.st_bottom = NULL;
}

/**
 * stack_is_empty - checks whether the stack is empty
 *
 * @st: pointer to the pointer to the top most element/node
 *      of the stack
 *
 * Return: <true> if the stack is empty, <false> otherwise
 */
bool stack_is_empty(stack_t **st)
{
	return ((!st || !(*st)) ? true : false);
}

/**
 * stack_top - displays the topmost element of the stack
 *
 * @st: pointer to the pointer to the top most element/node
 *      of the stack
 *
 * Return: integer value of the element on top of the stack
 */
int stack_top(stack_t **st)
{
	return ((*st)->n);
}

/**
 * stack_free_all - release the memory allocated for all the
 * elements (nodes) in the stack
 *
 * @st: pointer to pointer to the first element in the stack
 *
 * Return: nothing
 */
void stack_free_all(stack_t *st)
{
	stack_t *temp;

	if (!st)
		return;

	while (st)
	{
		temp = st->prev;
		free(st);
		st = temp;
	}

	essential.stack_size = 0;
	essential.st_top = NULL;
	essential.st_bottom = NULL;
}
