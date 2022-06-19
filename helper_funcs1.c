#include "monty.h"

/**
 * _push - Push int onto stack
 * @stack: Stack to push to
 * @line_number: Number line
 *
 * Return: Nothing
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!_isdigit(data.n))
	{
		fprintf(stderr, PUSH_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	n = atoi(data.n);
	add_dnodeint(stack, n);
}

/**
 * _pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}

/**
 * _pint - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, PINT_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * _pop - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, POP_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}

/**
 * _swap - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, SWAP_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		exit_op();
		exit(EXIT_FAILURE);
	}
}
