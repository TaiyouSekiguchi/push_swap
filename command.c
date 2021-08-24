#include "push_swap.h"

void	do_swap(t_stack *stack)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	tmp1 = stack->up->down;
	tmp2 = stack->up->down->down;
	if (stack == NULL || stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
	{
		stack->up->down->up = stack;
		stack->up->down->down = stack->up;
		stack->up->up = tmp1;
		stack->up->down = stack;
		stack->up = tmp1;
		stack->down = tmp1->down;
	}
	else
	{
		stack->up->down->up = stack;
		stack->up->down->down = stack->up;
		stack->up->up = tmp1;
		stack->up->down = tmp2;
		tmp2->up = stack->up;
		stack->up = tmp1;
	}
}

void	do_push(t_stack *src, t_stack *dst)
{
	t_stack		*tmp;

	if (src == NULL || dst == NULL)
		return ;
	if (stack_size(src) <= 0)
		return ;
	if (stack_size(src) == 1)
	{
		add_top(dst, src->up);
		src->up = NULL;
		src->down = NULL;
	}
	else if (stack_size(src) >= 2)
	{
		tmp = src->up->down;
		add_top(dst, src->up);
		src->up = tmp;
		tmp->up = src;
	}
}

void	do_rotate(t_stack *stack)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
		do_swap(stack);
	else
	{
		tmp1 = stack->up->down;
		stack->down->down = stack->up;
		stack->up->up = stack->down;
		stack->up->down = stack;
		tmp1->up = stack;
		
		tmp2 = stack->up;
		stack->up = tmp1;
		stack->down = tmp2;
	}
}

void	do_reverse(t_stack *stack)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (stack_size(stack) < 2)
		return ;
	else if (stack_size(stack) == 2)
		do_swap(stack);
	else
	{
		tmp1 = stack->down->up;

		stack->down->down = stack->up;
		stack->down->up = stack;
		stack->up->up = stack->down;
		tmp1->down = stack;
		
		tmp2 = stack->down;
		stack->down = tmp1;
		stack->up = tmp2;
	}
}
