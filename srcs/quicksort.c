#include "../includes/stack.h"
#include "../includes/operations.h"
#include "../includes/stack_utils.h"
#include "../includes/push_swap.h"
#include "../includes/split.h"

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
