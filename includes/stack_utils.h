#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "stack.h"

int		getTop(t_stack *s);
int		get_top_index(t_stack *s, int top);
t_bool	topIsGreater(t_stack *s);
t_bool	topIsBelow(t_stack *s);

#endif
