#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	while (*stack != NULL && (*stack)->n != 0 && isprint((*stack)->n))
	{
		printf("%c", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("\n");
}
