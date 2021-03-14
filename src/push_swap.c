#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/first_algo.h"

void	checking(t_stack* stack1, t_stack* stack2);
bool	checking_sort(t_stack* s);

#include <time.h>
#include <stdlib.h>
bool	doublon(t_stack* stack, int ipt){
	int i = 0;
	while (i < stack->size) {
		if (stack->stack[i] == ipt)
			return (true);
		i++;
	}
	return (false);
}


void	fill_first_stack(char* av[], t_stack* stack, int ac)
{
	int	i = 1;

	srand(time(NULL));
	int rdm = rand() % 100;
	ac--;
	while (ac != 0) {
		stack->stack[stack->size] = atoi(av[ac]);
		stack->size++;
		ac--;
	}	
	/*for (int i = 0; i < 500; i++)
	{
		while (doublon(stack, rdm) == true)
			rdm = rand() % 100000;
		stack->stack[stack->size] = rdm;
		stack->size++;
	}*/
}

void	free_stack(t_stack* stack1, t_stack* stack2)
{
	free(stack1->stack);
	free(stack2->stack);
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

void	display_stack(t_stack* stack1, t_stack* stack2)
{
	int i = stack1->size - 1;
	printf("\nFIRST_STACK\n");
	for (; i >= 0; i--)
		printf("%d\n", stack1->stack[i]);
	i = stack2->size - 1;
	printf("SECOND_STACK\n");
	for (; i >= 0; i--)
		printf("%d [%d]\n", stack2->stack[i], i);
}

int		get_pivot(t_stack* s, int size)
{
	int		ret;
	int		i;
	int		tmp;

	i = s->size - 1;
	ret = 0;
	tmp = size;
	while (size != 0)
	{
		ret += s->stack[i];
		i++;
		size--;
	}
	return (ret / tmp);
}

int		get_pivot_index(t_stack* s, int pivot)
{
	int		i;

	i = 0;
	while (i < s->size)
	{
		if (s->stack[i] == pivot)
			return (i);
		i++;
	}
	return (i);
}

bool	checkMinValue(t_stack* s, int value)
{
	int	i = 0;

	while (i < s->size)
	{
		if (s->stack[i] <= value)
			return (true);
		i++;
	}
	return (false);
}

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
		//printf("%d\n", i);
		c++;
	}
	if (ret == 0 || size == 0)
		printf("HA\n");
	return (ret / size);
}

void	stack3(t_stack* s1, t_stack* s2, int size)
{
	//printf("STACK3\n");
	for (int i = 0; i < size; i++)
		push_b(s1, s2);
	if (s2->size == 2)
	{
		if (topIsBelow(s2) == true)
			rotate_b(s2, write);
		while (s2->size != 0)
			push_a(s1, s2);
		while (size != 0)
		{
			rotate_a(s1, write);
			size--;
		}
		return;
	}
	if (topIsBelow(s2) == true) // [123] [132] [231]
	{
		if (s2->stack[2] > s2->stack[0]) //[231]
			swap_b(s2, write);
		else if (s2->stack[1] > s2->stack[0]) //[132]
			rotate_b(s2, write);
		else //[123]
		{
			swap_b(s2, write);
			reverse_rotate_b(s2, write);
		}
	}
	else // [213] [312] [321]
	{
		if (s2->stack[2] < s2->stack[0]) // [213]
			reverse_rotate_b(s2, write);
		else if (s2->stack[1] < s2->stack[0]) // [312]
		{
			reverse_rotate_b(s2, write);
			swap_b(s2, write);
		}
	}
	while (s2->size != 0)
		push_a(s1, s2);
	while (size != 0)
	{
		rotate_a(s1, write);
		size--;
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
			push_b(s1, s2);
		else if (s1->stack[s1->size - 1] <= pivot)
			push_b(s1, s2);
		else
		{
			rotate_a(s1, write);
			rotation++;
		}
		i++;
		//display_stack(s1, s2);
	}
	while (rotation != 0)
	{
		reverse_rotate_a(s1, write);
		rotation--;
	}
	//	ALGO STACKSIZE <= 3
	//if (s2->size <= 3)
	//	stack3(s1, s2);
	while (s2->size != 0)
	{
		push_a(s1, s2);
	}
}

bool	checking_sort(t_stack* s);
void    quicksort(t_stack* s1, t_stack* s2, int size)
{
	int	pivot;
	
	//display_stack(s1, s2);
	//sleep(1);
	if (chunkStackisSort(s1, size) == true && size > 3)
	{
		//printf("\nBEFORE ROTATE\n");
		//display_stack(s1, s2);
		if (checking_sort(s1) == false)
		{
			printf("SIZE %d\n", size);
			for (int i = 0; i < size; i++)
				rotate_a(s1, write);
		}
		//printf("\nAFTER ROTATE\n");
		//display_stack(s1, s2);
        	return;
	}
	if (size > 3)
		split(s1, s2, size);
	else
	{
		stack3(s1, s2, size);
		return;
	}
	quicksort(s1, s2, size / 2);
	if (size % 2 != 0)
		size++;
	quicksort(s1, s2, size / 2);
}

void	second_algo(t_stack* s1, t_stack* s2)
{
	quicksort(s1, s2, s1->size);
	if (s1->stack[s1->size - 1] > s1->stack[s1->size - 2])
		rotate_a(s1, write);
}

bool	checking_sort(t_stack* s)
{
	int		i;

	if (s->size <= 1)
		return (true);
	i = s->size - 1;
	while (i > 0)
	{
		//printf("[%d] [%d] [%d]\n", s->stack[i], s->stack[i-1], s->stack[i] - s->stack[i-1]);
		if (s->stack[i] > s->stack[i - 1])
			return (false);
		i--;
	}
	return (true);
}

void	checking(t_stack* stack1, t_stack* stack2)
{
	/*if (checking_sort(stack1) == true)
		printf("The stack is sorted\n");
	else
		printf("Error, the stack isn't sorted\n");	
*/}

int		main(int ac, char* av[])
{
	t_stack		stack1;
	t_stack		stack2;

	if (ac < 2)
		return (0);
	g_step = 0;
	stack1.stack = malloc(sizeof(int) * ac - 1);
	stack1.size = 0;
	stack2.stack = malloc(sizeof(int) * ac - 1);
	stack2.size = 0; 
	fill_first_stack(av, &stack1, ac);
	//printf("START\n");
	//display_stack(&stack1, &stack2);
	/**/
	//first_algo(&stack1, &stack2);
	second_algo(&stack1, &stack2);
	/**/
	//printf("\nEND");
	//display_stack(&stack1, &stack2);
	checking(&stack1, &stack2);
	free_stack(&stack1, &stack2);
	//printf("STEP => %d\n", g_step);
	return (0);
}
