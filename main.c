#include "monty.h"

char *argtoint;

/**
 * split_str - splits a string into tokens
 * @buf: The character to print
 * Return: array of strings.
 */
char **split_str(char *buf)
{
	char *token, **eachstr, *delim;
	int count = 0;

	delim = " \t\r\n\a";
	eachstr = malloc(sizeof(*eachstr) * 100);
	if (!eachstr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(buf, delim);
	while (token)
	{
		eachstr[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	eachstr[count] = NULL;

	return (eachstr);
}
/**
 * main - main program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename, *line = NULL;
	ssize_t linesize;
	int linecount = 0;
	size_t len = 0;
	char **fileargs;
	stack_t *h = NULL;
	void (*func)(stack_t **, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		filename = argv[1];
	fp = fopen(filename, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	linesize = getline(&line, &len, fp);
	while (linesize > 0)
	{
		linecount++;
		fileargs = split_str(line);
		func = get_func(fileargs[0]);
		if (!func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linecount, fileargs[0]);
			exit(EXIT_FAILURE);
		}
		if (fileargs[1])
			argtoint = fileargs[1];
		func(&h, linecount);
		linesize = getline(&line, &len, fp);
	}
	free(line);
	fclose(fp);
	return (1);
}
