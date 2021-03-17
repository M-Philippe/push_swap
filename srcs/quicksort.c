#include "../includes/stack.h"
#include "../includes/operations.h"
#include "../includes/stack_utils.h"
#include "../includes/push_swap.h"

t_bool	chunkStackisSort(t_stack *s1, int size)
{
	int	i;
	int	c;

	i = s1->size - 1;
	c = 0;
	if (s1->size == 1)
		return (TRUE);
	while (c < size)
	{
		if (s1->stack[i] > s1->stack[i - 1])
			return (FALSE);
		c++;
		i--;
	}
	return (TRUE);
}

int	chunkPivot(t_stack *s, int size)
{
	int	ret;
	int	i;
	int	c;

	i = s->size - 1;
	ret = 0;
	c = 0;
	while (c != size)
	{
		ret += s->stack[i];
		i--;
		c++;
	}
	return (ret / size);
}

void	handleMinCase(t_stack *s1, t_stack *s2)
{
	int	top;

	while (s2->size != 0)
	{
		top = getTop(s2);
		if (s2->size / 2 > get_top_index(s2, top))
			while (s2->stack[s2->size - 1] != top)
				reverse_rotate_b(s2, WRITE);
		else
			while (s2->stack[s2->size - 1] != top)
				rotate_b(s2, WRITE);
		push_a(s1, s2);
	}
}

void	split(t_stack *s1, t_stack *s2, int size)
{
	int	pivot;
	int	rotation;
	int	i;

	rotation = 0;
	pivot = chunkPivot(s1, size);
	i = 0;
	while (i < size)
	{
		if (size % 2 != 0 && s1->stack[s1->size - 1] < pivot)
			push_b(s1, s2);
		else if (size % 2 == 0 && s1->stack[s1->size - 1] <= pivot)
			push_b(s1, s2);
		else
		{
			rotate_a(s1, WRITE);
			rotation++;
		}
		i++;
	}
	while (rotation != 0 && s1->first_lap == FALSE)
	{
		reverse_rotate_a(s1, WRITE);
		rotation--;
	}
	s1->first_lap = FALSE;
	if (s2->size <= 27)
		handleMinCase(s1, s2);
	while (s2->size != 0)
	{
		push_a(s1, s2);
	}
}

void	quicksort(t_stack *s1, t_stack *s2, int size)
{
	int	i;

	i = 0;
	if (size == 1)
	{
		rotate_a(s1, WRITE);
		return ;
	}
	if (chunkStackisSort(s1, size) == TRUE)
	{
		if (checking_sort(s1) == FALSE)
		{
			while (i < size)
			{
				rotate_a(s1, WRITE);
				i++;
			}
		}
		return ;
	}
	split(s1, s2, size);
	quicksort(s1, s2, size / 2);
	if (size % 2 != 0)
		size++;
	quicksort(s1, s2, size / 2);
}
