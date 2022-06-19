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
			if (!data.n)
			{
				fprintf(stderr, PUSH_FAIL, data.line_number);
				exit_op();
				exit(EXIT_FAILURE);
			}
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
}
