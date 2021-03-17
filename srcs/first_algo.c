#include "../includes/first_algo.h"
#include "../includes/operations.h"

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

int		idx_top(t_stack *s)
{
	int		i;
	int		max;

	i = 0;
	max = top(s);
	while (i < s->size)
	{
		if (max == s->stack[i])
			return (i);
		i++;
	}
	return (0);
}

void	before_push(t_stack* s1, t_stack *s2)
{
	int i;
	int	index_top;

	i = 0;
	index_top = 0;
	while (s2->size != 1)
	{
		//	idx = top;
		index_top = idx_top(s2);
		while (i < s2->size)
		{
			if (s2->stack[s2->size - 1] == top(s2))
				push_b(s1, s2); //
			// if index < size / 2 -> reverse
			if (index_top < s2->size / 2)
				reverse_rotate_b(s2, write);
			else
				rotate_b(s2, write);
			i++;
		}
		i = 0;
	}
}

void	second_step(t_stack* stack1, t_stack* stack2)
{
	while (stack2->size != 0)
	{
		if (topIsBelow(stack2) == true)
			swap_b(stack2, write);
		push_b(stack1, stack2); //
		if (topIsGreater(stack1) == true)
			swap_a(stack1, write);
	}
}

void	first_algo(t_stack* s1, t_stack* s2)
{
	first_step(s1, s2);
	before_push(s1, s2);
	second_step(s1, s2);
}
