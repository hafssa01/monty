#include "monty.h"


/**
 * ats - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @l_num: Interger representing the line number of of the opcode.
 */
void ats(stack_t **new_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * prt_s - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: line number of  the opcode.
 */
void prt_s(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_t - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void pop_t(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		mr_err(7, l_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * prt_t - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void prt_t(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		mr_err(6, l_num);
	printf("%d\n", (*stack)->n);
}
