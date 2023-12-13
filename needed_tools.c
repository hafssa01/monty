#include "monty.h"

/**
 * o_f - opens a file
 * @f_n: the file namepath
 * Return: void
 */

void o_f(char *f_n)
{
	FILE *fd = fopen(f_n, "r");

	if (f_n == NULL || fd == NULL)
		con_err(2, f_n);

	r_f(fd);
	fclose(fd);
}


/**
 * r_f - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void r_f(FILE *fd)
{
	int l_num, frt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buffer, &len, fd) != -1; l_num++)
	{
		frt = p_l(buffer, l_num, frt);
	}
	free(buffer);
}


/**
 * p_l - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @l_num: line number
 * @frt:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int p_l(char *buffer, int l_num, int frt)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		con_err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (frt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fct(opcode, value, l_num, frt);
	return (frt);
}

/**
 * find_fct - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @frt:  storage frt. If 0 Nodes will be entered as a stack.
 * @l_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_fct(char *opcode, char *value, int l_num, int frt)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", ats},
		{"pall", prt_s},
		{"pint", prt_t},
		{"pop", pop_t},
		{"nop", nope},
		{"swap", sp_nds},
		{"add", add_nds},
		{"sub", sub_nds},
		{"div", div_nds},
		{"mul", mul_nds},
		{"mod", mod_nds},
		{"pchar", prt_cr},
		{"pstr", prt_str},
		{"rotl", rot_l},
		{"rotr", rtr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fct(func_list[i].f, opcode, value, l_num, frt);
			flag = 0;
		}
	}
	if (flag == 1)
		con_err(3, l_num, opcode);
}


/**
 * call_fct - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @l_num: line numeber for the instruction.
 * @frt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fct(op_func func, char *op, char *val, int l_num, int frt)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			con_err(5, l_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				con_err(5, l_num);
		}
		node = create_node(atoi(val) * flag);
		if (frt == 0)
			func(&node, l_num);
		if (frt == 1)
			atq(&node, l_num);
	}
	else
		func(&head, l_num);
}
