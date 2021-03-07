#include "../includes/operations.h"

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

void	rotate_a(t_stack* s, int flag)
{
	int		tmp;
	int		tmp2;
	int		i;

	if (s->size < 2)
		return;
	i = 0;
	tmp = s->stack[0];
	while (i < s->size)
	{
		tmp2 = s->stack[i];
		s->stack[i] = tmp;
		tmp = tmp2;
		i++;
	}
	s->stack[0] = tmp2;
	if (flag == write)
		printf("Rotate A\n");
}

void	rotate_b(t_stack* s, int flag)
{
	int		tmp;
	int		tmp2;
	int		i;

	if (s->size < 2)
		return;
	i = 0;
	tmp = s->stack[0];
	while (i < s->size)
	{
		tmp2 = s->stack[i];
		s->stack[i] = tmp;
		tmp = tmp2;
		i++;
	}
	s->stack[0] = tmp2;
	if (flag == write)
		printf("Rotate B\n");
}

