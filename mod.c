#include "monty.h"

/**
 * moddy - computes the rest of the division of the second top element of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = mod;
}
