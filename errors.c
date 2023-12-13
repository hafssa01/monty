#include "monty.h"

/**
 * con_err - Prints appropiate error messages determined by their error code.
 * @e_c: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void con_err(int e_c, ...)
{
	va_list ar_g;
	char *opr;
	int l_n;

	va_start(ar_g, e_c);
	switch (e_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ar_g, char *));
			break;
		case 3:
			l_n = va_arg(ar_g, int);
			opr = va_arg(ar_g, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_n, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ar_g, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * mr_err - handles errors.
 * @e_c: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void mr_err(int e_c, ...)
{
	va_list ar_g;
	char *opr;
	int l_n;

	va_start(ar_g, e_c);
	switch (e_c)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ar_g, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ar_g, int));
			break;
		case 8:
			l_n = va_arg(ar_g, unsigned int);
			opr = va_arg(ar_g, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_n, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ar_g, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * strerr - handles errors.
 * @e_c: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void strerr(int e_c, ...)
{
	va_list ar_g;
	int l_n;

	va_start(ar_g, e_c);
	l_n = va_arg(ar_g, int);
	switch (e_c)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_n);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
