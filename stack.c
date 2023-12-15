#include "monty.h"
/**
 * push  - opcode and its function
 * @stack: the opcode
 * @value: function to handle the opcode
 */
void push(stack_t **stack, int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
/**
 * pop - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
