#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	if (stack == NULL)
		return ;
	stack->up = NULL;
	stack->down = NULL;
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->up == NULL || stack->down == NULL)
		return ;
	current = stack->up;
	printf("%d\n", current->value);
	current = current->down;
	while (current != stack)
	{
		printf("%d\n", current->value);
		current = current->down;
	}
	printf("stack size is %d\n", stack_size(stack));
}
