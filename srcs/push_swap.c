#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/stack.h"
#include "../includes/operations.h"
#include "../includes/quicksort.h"
#include "../includes/stack_utils.h"

void	checking(t_stack *stack1);
t_bool	checking_sort(t_stack *s);

void	first_algo(t_stack *s1, t_stack *s2);

void	fill_first_stack(char *av[], t_stack *stack, int ac)
{
	ac--;
	while (ac != 0)
	{
		stack->stack[stack->size] = atoi(av[ac]);
		stack->size++;
		ac--;
	}
}

void	free_stack(t_stack *stack1, t_stack *stack2)
{
	free(stack1->stack);
	free(stack2->stack);
}

void	display_stack(t_stack *s1, t_stack *s2)
{
	int	i;

	i = 0;
	printf("FIRST | SECOND\n");
	if (s1->size > s2->size)
		i = s1->size - 1;
	else
		i = s2->size - 1;
	while (i >= 0)
	{
		if (i < s1->size)
			printf("%d", s1->stack[i]);
		printf("   |   ");
		if (i < s2->size)
			printf("%d", s2->stack[i]);
		printf("\n");
		i--;
	}
}

int	get_pivot(t_stack *s, int size)
{
	int	ret;
	int	i;
	int	tmp;

	i = s->size - 1;
	ret = 0;
	tmp = size;
	while (size != 0)
	{
		ret += s->stack[i];
		i++;
		size--;
	}
	return (ret / tmp);
}

int	get_pivot_index(t_stack *s, int pivot)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->stack[i] == pivot)
			return (i);
		i++;
	}
	return (i);
}

void	second_algo(t_stack *s1, t_stack *s2)
{
	quicksort(s1, s2, s1->size);
	if (s1->stack[s1->size - 1] > s1->stack[s1->size - 2])
		rotate_a(s1, WRITE);
}

t_bool	checking_sort(t_stack *s)
{
	int	i;

	if (s->size <= 1)
		return (TRUE);
	i = s->size - 1;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (FALSE);
		i--;
	}
	return (TRUE);
}

void	checking(t_stack *stack1)
{
	if (checking_sort(stack1) == TRUE)
		printf("The stack is sorted\n");
	else
		printf("Error, the stack isn't sorted\n");
}

void	stack3(t_stack *s1)
{
	if (topIsBelow(s1) == TRUE && s1->stack[2] > s1->stack[0])
		reverse_rotate_a(s1, WRITE);
	else if (topIsBelow(s1) == TRUE && s1->stack[2] < s1->stack[0])
	{
		reverse_rotate_a(s1, WRITE);
		swap_a(s1, WRITE);
	}
	else if (topIsGreater(s1) == TRUE && s1->stack[1] < s1->stack[0]
		&& s1->stack[2] < s1->stack[0])
		swap_a(s1, WRITE);
	else if (topIsGreater(s1) == TRUE && s1->stack[1] < s1->stack[0]
		&& s1->stack[2] > s1->stack[0])
		rotate_a(s1, WRITE);
	else if (topIsGreater(s1) == TRUE && s1->stack[1] > s1->stack[0]
		&& s1->stack[2] > s1->stack[0])
	{
		swap_a(s1, WRITE);
		reverse_rotate_a(s1, WRITE);
	}
}

int	main(int ac, char *av[])
{
	t_stack		stack1;
	t_stack		stack2;

	if (ac < 2)
		return (0);
	g_step = 0;
	stack1.stack = malloc(sizeof(int) * ac - 1);
	stack1.size = 0;
	stack1.first_lap = TRUE;
	stack2.stack = malloc(sizeof(int) * ac - 1);
	stack2.size = 0;
	fill_first_stack(av, &stack1, ac);
	if (stack1.size != 1 && checking_sort(&stack1) == FALSE)
	{
		if (stack1.size == 2 && topIsGreater(&stack1) == TRUE)
			swap_a(&stack1, WRITE);
		else if (stack1.size == 3)
			stack3(&stack1);
		else if (stack1.size <= 20)
			first_algo(&stack1, &stack2);
		else
			second_algo(&stack1, &stack2);
	}
	free_stack(&stack1, &stack2);
	return (0);
}
