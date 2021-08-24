#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*up;
	struct s_stack	*down;
}					t_stack;

t_stack	*new_data(int value);
int		stack_size(t_stack *stack);
void	add_top(t_stack *stack, t_stack *new);
void	stack_clear(t_stack *stack);
void	do_stack(t_stack *stack, int value);

void	do_swap(t_stack *stack);
void	do_push(t_stack *src, t_stack *dst);
void	do_rotate(t_stack *stack);
void	do_reverse(t_stack *stack);


void	stack_init(t_stack *stack);
void	print_stack(t_stack *stack);
#endif
