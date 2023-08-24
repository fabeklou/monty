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
