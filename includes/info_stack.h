#ifndef INFO_STACK_H
# define INFO_STACK_H

#include "stack.h"

int	getTop(t_stack *s);
int	get_top_index(t_stack *s, int top);
bool	topIsGreater(t_stack *s);
bool	topIsBelow(t_stack *s);

#endif
