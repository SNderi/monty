#include "monty.h"

data_t data;
void data_init(void);

/**
 * main - monty interpreter
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	size_t len = 0;
	ssize_t read;
	char *tok = NULL;
	char *delim = " \n\t\r";

	if (ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	data_init();
	data.fp = fopen(av[1], "r");
	if (data.fp == NULL)
	{
		fprintf(stderr, FILE_ERROR, av[1]);
		exit(EXIT_FAILURE);
	}

	read = getline(&(data.buff), &len, data.fp);
	while (read >= 0)
	{
		data.line_number += 1;
		tok = strtok(data.buff, delim);
		if (tok && tok[0] != '#')
		{
			data.n = strtok(NULL, delim);
			get_func(tok);
		}
		read = getline(&(data.buff), &len, data.fp);
		tok = NULL;
	}
	exit_op();
	return (0);
}

/**
 * data_init - initializes global variables
 */

void data_init(void)
{
	data.buff = NULL;
	data.n = NULL;
	data.stack = NULL;
	data.line_number = 0;
	data.flag = 1;
}

/**
 * _stack - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.flag = 1;
}

/**
 * _queue - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.flag = 2;
}
