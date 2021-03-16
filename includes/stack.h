#ifndef STACK_H
# define STACK_H

typedef int bool;
#define true 0
#define false 1

int	g_step;

typedef	struct s_stack
{
	int*	stack;
	int	size;
	bool	first_lap;
}		t_stack;

#endif
