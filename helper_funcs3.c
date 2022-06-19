#include "monty.h"

/**
 * _mod - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, MOD_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, DIV_ZERO, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mod);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		exit_op();
		exit(EXIT_FAILURE);
	}
}

/**
 * _pchar - Handles pchar function
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, PCHAR_FAIL, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, OUT_OF_RANGE, line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * _pstr - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}

/**
 * _rotl - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * _rotr - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;
	int len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}
