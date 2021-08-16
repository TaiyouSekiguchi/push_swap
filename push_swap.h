#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct		s_data
{
	int				value;
	struct s_data	*up;
	struct s_data	*down;
}					t_data;

typedef struct		s_stack
{
	t_data			*top;
	t_data			*bottom;
}					t_stack;

t_data	*new_data(int value);
int		stack_size(t_stack *stack);
void	add_top(t_stack *stack, t_data *new);
void	stack_clear(t_stack *stack);
void	do_stack(t_stack *stack, int value);

void	do_swap(t_stack *stack);
void	do_push(t_stack *src, t_stack *dst);
void	do_rotate(t_stack *stack);
void	do_reverse(t_stack *stack);


void	stack_init(t_stack *stack);
void	print_stack(t_stack *stack);
#endif
