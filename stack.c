#include "push_swap.h"

t_data	*new_data(int value)
{
	t_data		*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->up = NULL;
	new->down = NULL;
	return (new);
}

int		stack_size(t_stack *stack)
{
	int			count;
	t_data		*current;

	if (stack == NULL)
		return (0);
	if (stack->top == NULL || stack->bottom == NULL)
		return (0);
	count = 1;
	current = stack->bottom;
	while (current->up != (t_data *)stack)
	{
		count++;
		current = current->up;
	}
	return (count);
}

void	add_top(t_stack *stack, t_data *new)
{
	t_data		*tmp_top;

	if (stack == NULL || new == NULL)
		return ;
	if (stack->top == NULL && stack->bottom == NULL)
	{
		stack->top = new;
		stack->bottom = new;
		new->up = (t_data *)stack;
		new->down = (t_data *)stack;
		return ;
	}
	tmp_top = stack->top;
	stack->top = new;
	tmp_top->up = new;
	new->up = (t_data *)stack;
	new->down = tmp_top;
}

void	stack_clear(t_stack *stack)
{
	t_data		*current;
	t_data		*tmp;

	if (stack == NULL)
		return ;
	if (stack->top == NULL || stack->bottom == NULL)
		return ;
	current = stack->bottom;
	tmp = current->up;
	free(current);
	current = tmp;
	while (current != (t_data *)stack)
	{
		tmp = current->up;
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
}

void	do_stack(t_stack *stack, int value)
{
	t_data		*new;

	new = new_data(value);
	add_top(stack, new);
}
