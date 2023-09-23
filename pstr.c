#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	tmp = *stack;
	while (tmp != NULL && tmp->n != 0 && isprint(tmp->n))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
