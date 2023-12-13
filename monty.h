#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void o_f(char *f_n);
int p_l(char *buffer, int l_num, int frt);
void r_f(FILE *);
int len_chars(FILE *);
void find_fct(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void prt_s(stack_t **, unsigned int);
void ats(stack_t **, unsigned int);
void atq(stack_t **, unsigned int);

void call_fct(op_func, char *, char *, int, int);

void prt_t(stack_t **, unsigned int);
void pop_t(stack_t **, unsigned int);
void nope(stack_t **, unsigned int);
void sp_nds(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nds(stack_t **, unsigned int);
void sub_nds(stack_t **, unsigned int);
void div_nds(stack_t **, unsigned int);
void mul_nds(stack_t **, unsigned int);
void mod_nds(stack_t **, unsigned int);

/*String operations*/
void prt_cr(stack_t **, unsigned int);
void prt_str(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);

/*Error hanlding*/
void con_err(int error_code, ...);
void mr_err(int error_code, ...);
void strerr(int error_code, ...);
void rtr(stack_t **, unsigned int);

#endif
