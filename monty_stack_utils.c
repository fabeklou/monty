#include "monty.h"

/**
 * stack_display - prints value of all the elements in the stack
 * from the top of the stack
 *
 * @st: pointer to the top most element in the stack
 *
 * Return: nothing
 */
void stack_display(stack_t *st)
{
	while (st)
	{
		printf("%d\n", st->n);
		st = st->prev;
	}
}

/**
 * en_queue - treats the stack as a queue by adding a new element
 * at the end of the doubly linked list
 *
 * @st: pointer to the pointer to the top most element/node
 *      of the stack
 * @data: the data/element to be added
 *
 * Return: 1 representing failure, if malloc fail, 0 otherwise
 */
int en_queue(stack_t **st, int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		return (1);

	node->n = data;
	node->prev = NULL;
	node->next = *st;
	if (*st)
		(*st)->prev = node;

	essential.stack_size++;
	essential.st_bottom = node;

	if (essential.stack_size == 1)
		essential.st_top = node;

	return (0);
}
