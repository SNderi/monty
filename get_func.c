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
		/**
		*{"pall", _pall},
		*{"pint", _pint},
		*{"pop", _pop},
		*{"swap", _swap},
		*{"add", _add},
		*{"nop", _nop},
		*{NULL, NULL}
		*/
	};

	for (i = 0; opcodes[i].opcode && opc; i++)
	{
		if (!strcmp(opc, opcodes[i].opcode))
		{
			opcodes[i].f(&(data.stack), data.line_number);
			return (0);
		}
	}
	fprintf(stderr, UNKNOWN, data.line_number, opc);
	exit(EXIT_FAILURE);
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
