#include "push_swap.h"

//test is OK!!
void	chunk_init(int *chunk, size_t len)
{
	int		i;

	if (chunk == NULL || len < 0)
		return ;
	i = 0;
	while (i < len)
	{
		chunk[i] = INT_MAX;
		i++;
	}
}

//test is OK!!
int		chunk_check(int *chunk, size_t len, int value)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (chunk[i] == value)
			return (1);
		i++;
	}
	return (0);
}

//toriaezu ugoku yo
void	make_chunk(t_stack *stack, int *chunk, size_t len)
{
	t_data	*current;
	int		tmp1;
	int		tmp2;
	int		i;
	int		j;

	if (stack == NULL || chunk == NULL || len < 0)
		return ;
	current = stack->top;
	chunk[0] = current->value;
	current = current->down;
	while (current != (t_data *)stack)
	{
		i = 0;
		while (i < len)
		{
			if (current->value < chunk[i])
			{
				tmp1 = chunk[i];
				chunk[i] = current->value;
				j = 1;
				while (i + j < len)
				{
					tmp2 = tmp1;
					tmp1 = chunk[i + j];
					chunk[i + j] = tmp2;
					j++;
				}
				break ;
			}
			i++;
		}
		current = current->down;
	}
}

//test is OK!!
int		stack_chunk_match(t_stack *stack, int *chunk, size_t len)
{
	t_data	*current;
	int		spot;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL || chunk == NULL || len < 0)
		return (-1);
	current = stack->top;
	spot = 0;
	if (chunk_check(chunk, len, current->value))
		return (spot);
	current = current->down;
	spot++;
	while (current != (t_data *)stack)
	{
		if (chunk_check(chunk, len, current->value))
			return (spot);
		current = current->down;
		spot++;
	}
	return (-1);
}

//test OK!!
int		stack_biggest(t_stack *stack)
{
	t_data	*current;
	int		biggest;
	int		spot;
	int		count;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL)
		return (-1);
	current = stack->top;
	biggest = current->value;
	spot = 0;
	count = 0;
	current = current->down;
	count++;
	while (current != (t_data *)stack)
	{
		if (biggest < current->value)
		{
			biggest = current->value;
			spot = count;
		}
		current = current->down;
		count++;
	}
	return (spot);
}


int		max_check(t_stack *stack, int arg)
{
	t_data	*current;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL)
		return (0);
	current = stack->top;
	if (arg < current->value)
		return (0);
	current = current->down;
	while (current != (t_data *)stack)
	{
		if (arg < current->value)
			return (0);
		current = current->down;
	}
	return (1);
}

int		min_check(t_stack *stack, int arg)
{
	t_data	*current;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL)
		return (0);
	current = stack->bottom;
	if (arg < current->value)
		return (0);
	current = current->up;
	while (current != (t_data *)stack)
	{
		if (arg < current->value)
			return (0);
		current = current->up;
	}
	return (1);
}


void	stack_adjust(t_stack *stack, int arg)
{
	t_data	*current;
	int		amount;
	int		mid;
	int		spot;
	int		aim;
	int		cnt;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL)
		return ;
	if (stack_size(stack) < 2)
		return ;

	if (max_check(stack, arg) || min_check(stack, arg))
	{
		amount = stack_size(stack);
		mid = amount / 2;
		spot = stack_biggest(stack);
		if (spot <= mid)
		{
			while (spot-- > 0)
				do_rotate(stack);
		}
		else
		{
			while (amount - (spot++) > 0)
				do_reverse(stack);
		}
		return ;
	}

	aim = INT_MAX;
	current = stack->top;
	spot = 0;
	cnt = 0;
	if (arg > current->value)
		aim = current->value;
	current = current->down;
	cnt++;
	while (current != (t_data *)stack)
	{
		if (arg > current->value)
		{
			if (arg - current->value < arg - aim)
			{
				aim = current->value;
				spot = cnt;
			}
		}
		current = current->down;
		cnt++;
	}
	amount = stack_size(stack);
	mid = amount / 2;
	if (spot <= mid)
	{
		while (spot-- > 0)
			do_rotate(stack);
	}
	else
	{
		while (amount - spot++ > 0)
			do_reverse(stack);
	}
}


void	do_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_data	*current;
	int		*chunk;
	int		amount;
	int		mid;
	int		spot;

	chunk = (int *)malloc(sizeof(int) * 20);
	if (chunk == NULL)
		return ;
	
	while (stack_size(stack_a) != 0)
	{
		chunk_init(chunk, 20);
		make_chunk(stack_a, chunk, 20);
		while (stack_chunk_match(stack_a, chunk, 20) >= 0)
		{
			amount = stack_size(stack_a);
			mid = amount / 2;
			spot = stack_chunk_match(stack_a, chunk, 20);
			if (spot <= mid)
			{
				while (spot-- > 0)
					do_rotate(stack_a);
			}
			else
			{
				while (amount - (spot++) > 0)
					do_reverse(stack_a);
			}
			stack_adjust(stack_b, stack_a->top->value);
			do_push(stack_a, stack_b);
		}
	}

	while (stack_size(stack_b) != 0)
	{
		amount = stack_size(stack_b);
		mid = amount / 2;
		spot = stack_biggest(stack_b);
		if (spot <= mid)
		{
			while (spot-- > 0)
				do_rotate(stack_b);
		}
		else
		{
			while (amount - (spot++) > 0)
				do_reverse(stack_b);
		}
		do_push(stack_b, stack_a);
	}
}

void	first_stack(int *argc, char *argv[], t_stack *stack)
{
	int		value;
	int		i;
	int		j;

	i = 1;
	while (i < *argc)
	{
		j = 0;
		value = 0;
		while ((argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '\0')
		{
			value = value * 10 + (argv[i][j] - '0');
			j++;
		}
		do_stack(stack, value);
		i++;
	}
}


int		main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
	{
		printf("No arg is ERROR!!\n");
		return (0);
	}
	stack_init(&stack_a);
	stack_init(&stack_b);
	first_stack(&argc, argv, &stack_a);

	do_sort(&stack_a, &stack_b);

	printf("**********stack_a**********\n");
	print_stack(&stack_a);
	printf("**********stack_b**********\n");
	print_stack(&stack_b);

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
