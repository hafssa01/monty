#include "monty.h"

/**
 * prt_cr - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void prt_cr(stack_t **stack, unsigned int l_num)
{
	int a;

	if (stack == NULL || *stack == NULL)
		strerr(11, l_num);

	a = (*stack)->n;
	if (a < 0 || a > 127)
		strerr(10, l_num);
	printf("%c\n", a);
}

/**
 * prt_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void prt_str(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	int a;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		a = tmp->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot_l - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void rot_l(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rtr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_num: Interger representing the line number of of the opcode.
 */
void rtr(stack_t **stack, __attribute__((unused))unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
