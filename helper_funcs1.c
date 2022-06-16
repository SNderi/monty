#include "monty.h"

/**
 * _push - Push int onto stack
 * @stack: Stack to push to
 * @line_number: Number line
 *
 * Return: Nothing
 */

void _push (stack_t **stack, unsigned int line_number)
{
	int n;

	if (!isdigit(data.n))
	{
		fprintf(stderr, PUSH_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);	
	}
	n = atoi(data.n);
	add_dnodeint(stack, n);
}
