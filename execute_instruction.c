#include "monty.h"

/**
 * execute_instruction - function to execute given instructions
 * @stack : parametre to run the stack
 * @opcode : given command line arguement
 * @argument : Takes the arguement of the given command
 * @line_number : for iteration and calculating the number of lines
 * Description: function with multiple arguements for executing commands
 */
void execute_instruction(stack_t **stack, char *opcode, int argument, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
