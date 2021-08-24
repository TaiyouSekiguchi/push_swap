#include "push_swap.h"

t_stack	*new_data(int value)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
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
	t_stack		*current;

	if (stack == NULL)
		return (0);
	if (stack->up == NULL || stack->down == NULL)
		return (0);
	count = 1;
	current = stack->down;
	while (current->up != stack)
	{
		count++;
		current = current->up;
	}
	return (count);
}

void	add_top(t_stack *stack, t_stack *new)
{
	t_stack		*tmp_up;

	if (stack == NULL || new == NULL)
		return ;
	if (stack->up == NULL && stack->down == NULL)
	{
		stack->up = new;
		stack->down = new;
		new->up = stack;
		new->down = stack;
		return ;
	}
	tmp_up = stack->up;
	stack->up = new;
	tmp_up->up = new;
	new->up = stack;
	new->down = tmp_up;
}

void	stack_clear(t_stack *stack)
{
	t_stack		*current;
	t_stack		*tmp;

	if (stack == NULL)
		return ;
	if (stack->up == NULL || stack->down == NULL)
		return ;
	current = stack->down;
	tmp = current->up;
	free(current);
	current = tmp;
	while (current != stack)
	{
		tmp = current->up;
		free(current);
		current = tmp;
	}
	stack->up = NULL;
	stack->down = NULL;
}

void	do_stack(t_stack *stack, int value)
{
	t_stack		*new;

	new = new_data(value);
	add_top(stack, new);
}
