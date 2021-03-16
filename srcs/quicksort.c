#include "../includes/stack.h"
#include "../includes/operations.h"
#include "../includes/info_stack.h"
#include "../includes/push_swap.h"

bool	chunkStackisSort(t_stack* s1, int size)
{
	int	i;
	int	c;

	i = s1->size - 1;
	c = 0;
	if (s1->size == 1)
		return (true);
	while (c < size)
	{
		if (s1->stack[i] > s1->stack[i - 1])
			return (false);
		c++;
		i--;
	}
	return (true);
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

void	handleMinCase(t_stack* s1, t_stack* s2)
{
	int	top;

	while (s2->size != 0)
	{
		top = getTop(s2);
		if (s2->size / 2 > get_top_index(s2, top)) // rra
			while (s2->stack[s2->size - 1] != top)
				reverse_rotate_b(s2, write);
		else
			while (s2->stack[s2->size - 1] != top)
				rotate_b(s2, write);
		push_a(s1, s2);
	}
}

void	split(t_stack* s1, t_stack* s2, int size)
{
	int	pivot;
	int	rotation;

	rotation = 0;
	pivot = chunkPivot(s1, size);
	int i = 0;
	while (i < size)
	{
		if (size % 2 != 0 && s1->stack[s1->size - 1] < pivot)
			{ push_b(s1, s2);} //
		else if (size % 2 == 0 && s1->stack[s1->size - 1] <= pivot)
			push_b(s1, s2); //
		else
		{
			rotate_a(s1, write);
			rotation++;
		}
		i++;
	}
	while (rotation != 0 && s1->first_lap == false)
	{
		reverse_rotate_a(s1, write);
		rotation--;
	}
	s1->first_lap = false;
	if (s2->size <= 27)
		handleMinCase(s1, s2);
	while (s2->size != 0)
	{
		push_a(s1, s2); //
	}
}

void    quicksort(t_stack* s1, t_stack* s2, int size)
{
	if (size == 1){
		rotate_a(s1, write);
		return;}
	if (chunkStackisSort(s1, size) == true)
	{
		if (checking_sort(s1) == false)
		{
			for (int i = 0; i < size; i++)
				rotate_a(s1, write);
		}
        	return;
	}
	split(s1, s2, size);
	quicksort(s1, s2, size / 2);
	if (size % 2 != 0)
		size++;
	quicksort(s1, s2, size / 2);
}
