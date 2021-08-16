#include "push_swap.h"

void	do_swap(t_stack *stack)
{
	t_data		*tmp1;
	t_data		*tmp2;

	tmp1 = stack->top->down;
	tmp2 = stack->top->down->down;
	if (stack == NULL || stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
	{
		stack->top->down->up = (t_data *)stack;
		stack->top->down->down = stack->top;
		stack->top->up = tmp1;
		stack->top->down = (t_data *)stack;
		stack->top = tmp1;
		stack->bottom = tmp1->down;
	}
	else
	{
		stack->top->down->up = (t_data *)stack;
		stack->top->down->down = stack->top;
		stack->top->up = tmp1;
		stack->top->down = tmp2;
		tmp2->up = stack->top;
		stack->top = tmp1;
	}
}

void	do_push(t_stack *src, t_stack *dst)
{
	t_data		*tmp;

	if (src == NULL || dst == NULL)
		return ;
	if (stack_size(src) <= 0)
		return ;
	if (stack_size(src) == 1)
	{
		add_top(dst, src->top);
		src->top = NULL;
		src->bottom = NULL;
	}
	else if (stack_size(src) >= 2)
	{
		tmp = src->top->down;
		add_top(dst, src->top);
		src->top = tmp;
		tmp->up = (t_data *)src;
	}
}

void	do_rotate(t_stack *stack)
{
	t_data		*tmp1;
	t_data		*tmp2;

	if (stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
		do_swap(stack);
	else
	{
		tmp1 = stack->top->down;
		stack->bottom->down = stack->top;
		stack->top->up = stack->bottom;
		stack->top->down = (t_data *)stack;
		tmp1->up = (t_data *)stack;
		
		tmp2 = stack->top;
		stack->top = tmp1;
		stack->bottom = tmp2;
	}
}

void	do_reverse(t_stack *stack)
{
	t_data		*tmp1;
	t_data		*tmp2;

	if (stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
		do_swap(stack);
	else
	{
		tmp1 = stack->bottom->up;

		stack->bottom->down = stack->top;
		stack->bottom->up = (t_data *)stack;
		stack->top->up = stack->bottom;
		tmp1->down = (t_data *)stack;
		
		tmp2 = stack->bottom;
		stack->bottom = tmp1;
		stack->top = tmp2;
	}
}
