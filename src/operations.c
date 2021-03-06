#include "operations.h"

#include <stdio.h>

void	push_b(t_stack* stack1, t_stack* stack2)
{
	stack2->size++;
	stack2->stack[stack2->size - 1] = stack1->stack[stack1->size - 1];
	stack1->size--;
	printf("Push B\n");
	g_step += 1;
}

void	push_a(t_stack* stack1, t_stack* stack2)
{
	//printf("size1 [%d] || size2 [%d]\n", stack1->size, stack2->size);
	stack1->size++;
	stack1->stack[stack1->size - 1] = stack2->stack[stack2->size - 1];
	//stack1->size++;
	stack2->size--;
	printf("Push A\n");
	g_step += 1;
}

void	swap_b(t_stack* stack, int flag)
{
	int		tmp;

	if (stack->size <= 1)
		return;
	tmp = 0;
	tmp = stack->stack[stack->size - 2];
	stack->stack[stack->size - 2] = stack->stack[stack->size - 1];
	stack->stack[stack->size - 1] = tmp;
	if (flag == write)
		printf("Swap B\n");
	g_step += 1;
}

void	swap_a(t_stack* stack, int flag)
{
	int		tmp;

	if (stack->size <= 1)
		return;
	tmp = 0;
	tmp = stack->stack[stack->size - 2];
	stack->stack[stack->size - 2] = stack->stack[stack->size - 1];
	stack->stack[stack->size - 1] = tmp;
	if (flag == write)
		printf("Swap A\n");
	g_step += 1;
}

void	swap_both(t_stack* s1, t_stack* s2)
{
	swap_a(s1, no_write);
	swap_b(s2, no_write);
	printf("SS\n");
}
