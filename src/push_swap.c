#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/first_algo.h"

/*
 * 	SEGFAULT IF STACK ALREAY SORTED
*/



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

/*void	display_stack(t_stack* stack1, t_stack* stack2)
{
	int i = stack1->size - 1;
	printf("\nSTACK\n");
	for (; i >= 0; i--)
		printf("%d ", stack1->stack[i]);
	i = stack2->size - 1;
	printf("\n");
	for (; i >= 0; i--)
		printf("%d ", stack2->stack[i]);
	printf("\n");
}*/
void	display_stack(t_stack* s1, t_stack* s2)
{
	/*printf("\nSTACK\n");
	for (int i = 0; i < stack1->size; i++)
		printf("%d ", stack1->stack[i]);
	printf("\n");
	for (int i = 0; i < stack2->size; i--)
		printf("%d ", stack2->stack[i]);
	printf("\n");*/
	printf("FIRST | SECOND\n");
	int	i = 0;
	if (s1->size > s2->size)
		i = s1->size - 1;
	else
		i = s2->size - 1;
	for (; i >= 0; i--)
	{
		if (i < s1->size)
			printf("%d", s1->stack[i]);
		printf("   |   ");
		if (i < s2->size)
			printf("%d", s2->stack[i]);
		printf("\n");
	}
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

/*void	stack3(t_stack* s1, t_stack* s2, int size)
{
	//printf("STACK3\nSIZE %d\n", size);
	//display_stack(s1, s2);
	for (int i = 0; i < size; i++)
		push_b(s1, s2); //
	if (s2->size == 2)
	{
		if (topIsBelow(s2) == true)
			rotate_b(s2, write);
		while (s2->size != 0)
			push_a(s1, s2); //
		while (size != 0)
		{
			rotate_a(s1, write);
			size--;
		}
		//display_stack(s1, s2);
		return;
	}
	if (topIsBelow(s2) == true) // [123] [132] [231]
	{
		if (s2->stack[0] > s2->stack[2]) //[231]
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
		if (s2->stack[0] < s2->stack[2]) // [213]
			reverse_rotate_b(s2, write);
		else if (s2->stack[1] < s2->stack[0]) // [312]
		{
			reverse_rotate_b(s2, write);
			swap_b(s2, write);
		}
	}
	//display_stack(s1, s2);
	while (s2->size != 0)
		push_a(s1, s2); //
	while (size != 0)
	{
		rotate_a(s1, write);
		size--;
	}
}*/

/*
 * [321] OK
 * [132]	A	OK
 * [231]	B	OK
 * [213]	C
 * [312]	D	OK
 * [123]	E
*/

void	stack3(t_stack* s1, t_stack* s2, int size)
{
	if (chunkStackisSort(s1, 2) == true)
		return;
	if (size == 2 && topIsGreater(s1) == true)
	{
		swap_a(s1, write);
		return;
	}
	else if (size == 2)
		return;
	for (int i = 0; i < 3; i++)
		push_b(s1, s2);
	display_stack(s1, s2);
	if (s2->stack[2] > s2->stack[0] && s2->stack[1] > s2->stack[0]) // B
		swap_b(s2, write);
	else if (s2->stack[2] > s2->stack[0] && s2->stack[1] < s2->stack[0]) // D
	{
		reverse_rotate_b(s2, write);
		swap_b(s2, write);
	}
	else if (s2->stack[2] < s2->stack[0] && s2->stack[1] > s2->stack[0]) // A
		rotate_b(s2, write);
	else if (s2->stack[2] < s2->stack[0] && s2->stack[2] > s2->stack[1]) // C
		reverse_rotate_b(s2, write);
	else if (s2->stack[2] < s2->stack[0] && s2->stack[2] < s2->stack[1]) // E
	{
		rotate_b(s2, write);
		swap_b(s2, write);
	}
	for (int i = 0; i < 3; i++)
		push_a(s1, s2);
}

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

void	handleMinCase(t_stack* s1, t_stack* s2, int size)
{
	int	top;

	//printf("TOP %d\n", size);
	//display_stack(s1,s2);
	top = getTop(s2);
	while (s2->size != 1)
	{
		if (s2->stack[s2->size - 1] == top)
		{
			push_a(s1, s2);
			top = getTop(s2);
		}
		rotate_b(s2, write);
	}
	push_a(s1, s2);
	//display_stack(s1,s2);
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
		//display_stack(s1, s2);
	}
	//printf("rot %d\n", rotation);
	//display_stack(s1, s2);
	while (rotation != 0)
	{
		reverse_rotate_a(s1, write);
		rotation--;
	}
	//if (s2->size <= 11)
	//	handleMinCase(s1, s2, size);
	while (s2->size != 0)
	{
		push_a(s1, s2); //
	}
}

bool	checking_sort(t_stack* s);
void    quicksort(t_stack* s1, t_stack* s2, int size)
{
	//printf("Quicksort [%d]\n", size);
	//display_stack(s1, s2);
	//sleep(1);
	if (size == 1){
		rotate_a(s1, write);
		return;}
	if (chunkStackisSort(s1, size) == true)
	{
		//printf("\nBEFORE ROTATE\n");
		//display_stack(s1, s2);
		if (checking_sort(s1) == false)
		{
			//printf("SIZE %d\n", size);
			for (int i = 0; i < size; i++)
				rotate_a(s1, write);
		}
		//printf("\nAFTER ROTATE\n");
		//display_stack(s1, s2);
        	return;
	}
	//if (size > 3)
		split(s1, s2, size);
	//else
	//	stack3(s1, s2, size);
	//while (s2->size != 0)
	//	push_a(s1, s2);
	quicksort(s1, s2, size / 2);
	if (size % 2 != 0)
		size++;
	//printf("Here\n");
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
	display_stack(&stack1, &stack2);
	/**/
	//first_algo(&stack1, &stack2);
	second_algo(&stack1, &stack2);
//	stack3(&stack1, &stack2, 3);
	/**/
	//printf("\nEND");
	display_stack(&stack1, &stack2);
	//checking(&stack1, &stack2);
	free_stack(&stack1, &stack2);
	//printf("STEP => %d\n", g_step);
	//return (0);
}
