#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point for the program
 *
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: Always 0, success
 */
int main(int argc, char **argv)
{
	FILE *fp;
	unsigned long int num;
	char *line;
	char *endptr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = readline(fp);
	while (line != NULL)
	{
		num = strtol(line, &endptr, 10);
		factorize(num);
		line = readline(fp);
	}
	return (0);
}

/**
 * factorize - prints a number as a product of two smaller numbers
 *
 * @num: number
 */
void factorize(unsigned long int num)
{
	unsigned long int i = 2;
	unsigned long int res;

	while (i < num)
	{
		res = num % i;
		if (res == 0)
		{
			printf("%lu=%lu*%lu\n", num, num/i, i);
			return;
		}
		i++;
	}
	printf("%lu\n", num);
	return;
}
