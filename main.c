#include "monty.h"
#define _GNU_SOURCE

data_t data;

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
	int read;
	char *tok = NULL;
	char *delim = " \n\t";

	if (ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	data.fp = fopen(av[1], "r");
	if (data.fp == NULL)
	{
		fprintf(stderr, FILE_ERROR, av[1]);
		exit(EXIT_FAILURE);
	}

	data_init();
	read = getline(&(data.buff), &len, data.fp);
	while (read >= 0)
	{
		data.line_number++;
		tok = strtok(data.buff, delim);
		data.n = strtok(NULL, delim);
		get_func(tok);
		read = getline(&(data.buff), &len, data.fp);
		tok = NULL;
		data.n = NULL;
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
