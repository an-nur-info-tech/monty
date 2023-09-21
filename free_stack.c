#include "monty.h"

/**
 * free_stck - frees a stack_t list.
 * @head: a pointer to the head
 *
 * Return: void
 */
void free_stck(stack_t *head)
{
	stack_t *next;

	if (!head)
		return;

	next = head;
	while (next != NULL)
	{
		head = next;
		next = head->next;
		free(head);
	}
}
