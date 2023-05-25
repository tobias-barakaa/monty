#include "monty.h"

/**
 * file_check - a function to check we have rights and can open a filestream
 * @fp: a pointer to a filestream
 * @filename: the name of the file
 **/
void file_check(FILE *fp, const char *filename)
{
	if (fp == NULL || access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * clean_up - a function to free up any allocated memory
 * @fp: a double pointer to our file stream
 * @stack: a double pointer to our memory stack
 * @buffer: adoubl pointer to our char buffer from getline
 **/
void clean_up(FILE **fp, stack_t **stack, char **buffer)
{
	stack_t *mover;

	if ((*fp) != NULL)
		fclose((*fp));
	if (*buffer != NULL)
		free(*buffer);
	while (*stack != NULL)
	{
		mover = (*stack);
		(*stack) = (*stack)->prev;
		free(mover);
	}
	free(info);
}
