#include "monty.h"

/**
 * get_func - selects the right function
 * @opc: Opcode to be found
 *
 * Return: pointer to the selected function, or NULL on failure
 */

int get_func(char *opc)
{
	int i;

	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rot1", _rot1},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode && opc; i++)
	{
		if (strcmp(opc, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(&(data.stack), data.line_number);
			return (0);
		}
	}
	fprintf(stderr, UNKNOWN, data.line_number, opc);
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - Check if str is a number
 * @d: string to check
 *
 * Return: 0 if not 1 if is
 */

int _isdigit(char *d)
{
	int i;

	for (i = 0; d[i]; i++)
	{
		if (d[i] == '-' && i == 0)
			continue;
		if (isdigit(d[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * exit_op - Exit operations
 */
void exit_op(void)
{
	free(data.buff);
	fclose(data.fp);
	free_dlistint(data.stack);
}
