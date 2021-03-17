#ifndef STACK_H
# define STACK_H

# define TRUE 0
# define FALSE 1

typedef int	t_bool;
int		g_step;
typedef struct s_stack
{
	int	*stack;
	int	size;
	t_bool	first_lap;
}	t_stack;

#endif
