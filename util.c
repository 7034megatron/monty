#include "monty.h"
/**
 * pall - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;
        (void)line_number;
        while (current != NULL)
        {
                fprintf(stdout, "%d\n", current->n);
                current = current->next;
        }
}
/**
 * pint - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}
/**
 * swap - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
        int temp = (*stack)->n;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
}
/**
 * add - opcode and its function
 * @stack: the opcode
 * @line_number: function to handle the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
}
