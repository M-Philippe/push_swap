#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "push_swap.h"

typedef int bool;
#define true 0
#define false 1

#define write 0
#define no_write 1

int	g_step;

void	push_b(t_stack* stack1, t_stack* stack2);
void	swap_b(t_stack* stack, int flag);
void	swap_a(t_stack* stack, int flag);
void	push_a(t_stack* stack1, t_stack* stack2);
void	swap_both(t_stack* s1, t_stack* s2);
void	rotate_a(t_stack* s, int flag);
void	rotate_b(t_stack* s, int flag);

#endif
