#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	if (stack == NULL)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	print_stack(t_stack *stack)
{
	t_data	*current;

	if (stack == NULL || stack->top == NULL || stack->bottom == NULL)
		return ;
	current = stack->top;
	printf("%d\n", current->value);
	current = current->down;
	while (current != (t_data *)stack)
	{
		printf("%d\n", current->value);
		current = current->down;
	}
	printf("stack size is %d\n", stack_size(stack));
}
