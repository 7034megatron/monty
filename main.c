#define _GNU_SOURCE
#include <sys/types.h>
#include "monty.h"
#include <stdio.h>
/**
 * main - entrance into the main product
 * @argc: for the argc arguement
 * @argv: for the argv arguemntn
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char opcode[10];
	int argument = 0;
	size_t opcode_size = 0;
	ssize_t read_bytes = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char *line = NULL;/* Check if the file was included */

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	/* Open the file for reading */
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Read lines from the file */
	while ((read_bytes = getline(&line, &opcode_size, file)) != -1)
	{
		line_number++;
		if (sscanf(line, "%s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				/* If it's the push opcode, read the argument */
				if (sscanf(line, "%*s %d", &argument) != 1)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* If it's any other opcode, set the argument to 0 */
				argument = 0;
			}
			execute_instruction(&stack, opcode, argument, line_number);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS); /* Indicate successful program execution */
}
