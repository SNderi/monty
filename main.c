#include "monty.h"
#define _GNU_SOURCE

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
	FILE *fptr;
	char *buf = NULL;
	size_t len = 0;
	ssize_t read;
	char *tok = NULL;
	char *delim = " \n\t\r";

	if (ac != 2)
	{
		fprintf(stderr, USAGE);
		exit(EXIT_FAILURE);
	}

	fptr = fopen(av[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, FILE_ERROR, av[1]);
		exit(EXIT_FAILURE);
	}

	data.fp = fptr;
	data_init();
	read = getline(&buf, &len, data.fp);
	while (read >= 0)
	{
		data.line_number += 1;
		tok = strtok(buf, delim);
		if (tok && tok[0] != '#')
		{
			data.n = strtok(NULL, delim);
			get_func(tok);
		}
		read = getline(&buf, &len, data.fp);
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
