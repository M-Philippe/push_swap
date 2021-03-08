#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/push_swap.h"
#include "../includes/operations.h"


void	checking(t_stack* stack1, t_stack* stack2);
bool	checking_sort(t_stack* s);

#include <time.h>
#include <stdlib.h>
bool	doublon(t_stack* stack, int ipt){
	int i = 0;
	while (i < stack->size) {
		if (stack->stack[i] == ipt)
			return (true);
		i++;
	}
	return (false);
}

void	fill_first_stack(char* av[], t_stack* stack)
{
	int	i = 1;

	srand(time(NULL));
	int rdm = rand() % 100;
	/*while (av[i]) {
		stack->stack[stack->size] = atoi(av[i]);
		stack->size++;
		i++;
	}*/	
	for (int i = 0; i < 500; i++)
	{
		while (doublon(stack, rdm) == true)
			rdm = rand() % 100000;
		stack->stack[stack->size] = rdm;
		stack->size++;
	}
}

void	free_stack(t_stack* stack1, t_stack* stack2)
{
	free(stack1->stack);
	free(stack2->stack);
}

/*	Return TRUE if Top > Top-1 */
bool	topIsGreater(t_stack* s)
{
	if (s->size <= 1)
		return (false);
	if (s->stack[s->size - 1] > s->stack[s->size - 2])
		return (true);
	return (false);
}

/*	Return TRUE if Top < Top-1 */
bool	topIsBelow(t_stack* s)
{
	if (s->size <= 1)
		return (false);
	if (s->stack[s->size - 1] < s->stack[s->size - 2])
		return (true);
	return (false);
}

void	display_stack(t_stack* stack1, t_stack* stack2);
void	first_step(t_stack* stack1, t_stack* stack2)
{	
	while (stack1->size != 1)
	{
		if (topIsGreater(stack1) == true && topIsBelow(stack2) == true)
			swap_both(stack1, stack2);
		if (topIsGreater(stack1) == true)
			swap_a(stack1, write);
		push_b(stack1, stack2);
		if (topIsGreater(stack1) == true && topIsBelow(stack2) == true)
			swap_both(stack1, stack2);
		if (topIsGreater(stack1) == true)
			swap_a(stack1, write);
	}
}

bool	checking_sort_rev(t_stack* s)
{
	int		diff;
	int		i;

	i = 1;
	if (s->size <= 1)
		return (true);
	diff = s->stack[0];
	while (i < s->size)
	{
		if (s->stack[i] - diff > 0)
			return (false);
		diff = s->stack[i];
		i++;
	}
	return (true);
}

void	dis(t_stack* s)
{
	for (int i = s->size - 1; i >= 0; i--) {
		printf("%d [%d]\n", s->stack[i], i);
	}
}

bool	topIsBelowTmp(t_stack* s)
{
	if (s->size <= 1)
		return (false);
	if (s->stack[s->size - 1] < s->stack[s->size - 2])
		return (true);
	return (false);
}

int		minimum(t_stack *s)
{
	int		ret;
	int		i;

	ret = s->stack[0];
	i = 0;
	while (i < s->size)
	{
		if (ret > s->stack[i])
			ret = s->stack[i];
		i++;
	}
	return (ret);
}

int		top(t_stack *s)
{
	int		ret;
	int		i;

	ret = s->stack[0];
	i = 0;
	while (i < s->size)
	{
		if (ret < s->stack[i])
			ret = s->stack[i];
		i++;
	}
	return (ret);
}

void	before_push(t_stack* s1, t_stack *s2)
{
	int i;

	i = 0;
	while (s2->size != 1)
	{
		while (i < s2->size)
		{
			if (s2->stack[s2->size - 1] == top(s2))
				push_a(s1, s2);
			rotate_b(s2, write);
			i++;
		}
		i = 0;
	}
}

void	second_step(t_stack* stack1, t_stack* stack2)
{
	before_push(stack1, stack2);
	while (stack2->size != 0)
	{
		if (topIsBelow(stack2) == true)
			swap_b(stack2, write);
		push_a(stack1, stack2);
		if (topIsGreater(stack1) == true)
			swap_a(stack1, write);
	}
}

void	operate(t_stack *stack1, t_stack* stack2)
{
	first_step(stack1, stack2);
	second_step(stack1, stack2);
}

void	display_stack(t_stack* stack1, t_stack* stack2)
{
	int i = stack1->size - 1;
	printf("\nFIRST_STACK\n");
	for (; i >= 0; i--)
		printf("%d\n", stack1->stack[i]);
	i = stack2->size - 1;
	printf("SECOND_STACK\n");
	for (; i >= 0; i--)
		printf("%d [%d]\n", stack2->stack[i], i);
}

bool	checking_sort(t_stack* s)
{
	int		diff;
	int		i;

	i = 1;
	if (s->size <= 1)
		return (true);
	diff = s->stack[0];
	while (i < s->size)
	{
		if (s->stack[i] - diff > 0)
			return (false);
		diff = s->stack[i];
		i++;
	}
	return (true);
}

void	checking(t_stack* stack1, t_stack* stack2)
{
	if (checking_sort(stack1) == true)
		printf("The stack is sorted\n");
	else
		printf("Error, the stack isn't sorted\n");	
}

int		main(int ac, char* av[])
{
	t_stack		stack1;
	t_stack		stack2;

	//if (ac < 2)
	//	return (0);
	g_step = 0;
	// ac - 1
	stack1.stack = malloc(sizeof(int) * 500);
	stack1.size = 0;
	stack2.stack = malloc(sizeof(int) * 500);
	stack2.size = 0; 
	fill_first_stack(av, &stack1);
	display_stack(&stack1, &stack2);
	operate(&stack1, &stack2);
	printf("\nEND");
	display_stack(&stack1, &stack2);
	checking(&stack1, &stack2);
	free_stack(&stack1, &stack2);
	printf("STEP => %d\n", g_step);
	return (0);
}
