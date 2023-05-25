#include "monty.h"
#include <ctype.h>

glbnfo *info = NULL;

/**
 * main - our main function
 * @argc: a count of the number of args
 * @argv: an array of char pointers to arguments
 * Return: 0 for success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_size;
	unsigned int line_count = 0;
	int i = 0;
	char *cmd_toks;
	char *command[50];
	char delimit[] = " \t\n";
	const char *filename;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	file_check(fp, filename);
	info = malloc(sizeof(glbnfo));
	if (info == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	info->fp = &fp;
	info->buffer = &line_buf;
	line_size = getline(&line_buf, &line_buf_size, fp);
	while (line_size >= 0)
	{
		line_count += 1;
		cmd_toks = strtok(line_buf, delimit);
		while (cmd_toks != NULL)
		{
			command[i] = cmd_toks;
			cmd_toks = strtok(NULL, delimit);
			i++;
		}
		cmd_comp(command, &stack, line_count);
	    line_size = getline(&line_buf, &line_buf_size, fp);
	    i = 0;
	}
	clean_up(info->fp, &stack, info->buffer);
	return (0);
}
