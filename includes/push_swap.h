#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef int bool;
#define true 0
#define false 1

typedef	struct s_stack
{
	int*	stack;
	int	size;
	bool	first_lap;
}		t_stack;


void	display_stack(t_stack* stack1, t_stack* stack2);

#endif
