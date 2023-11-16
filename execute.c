#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
	{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
	{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
	{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
	{"mul", f_mul}, {"mod", f_mod}, {"pstr", f_pstr},
	{NULL, NULL}
	};
	unsigned int i;
	char *op = strtok(content, " \n\t");

	if (!op || op[0] == '#')
	return (0);

	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode; i++)
	{
	if (strcmp(op, opst[i].opcode) == 0)
	{
	opst[i].f(stack, counter);
	return (0);
	}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	return (EXIT_FAILURE);
}
