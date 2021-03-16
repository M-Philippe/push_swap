#include "../includes/info_stack.h"

int	getTop(t_stack *s)
{
	int	i;
	int	ret;

	i = 1;
	ret = s->stack[0];
	while (i < s->size)
	{
		if (ret < s->stack[i])
			ret = s->stack[i];
		i++;
	}
	return (ret);
}

int	get_top_index(t_stack *s, int top)
{
	int	i;

	i = s->size - 1;
	while (i >= 0)
	{
		if (s->stack[i] == top)
			return (i);
		i--;
	}
	return (i);
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
