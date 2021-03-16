#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../includes/stack.h"
#include "../includes/operations.h"
#include "../includes/quicksort.h"
#include "../includes/stack_utils.h"

void    checking(t_stack* stack1);
bool    checking_sort(t_stack* s);

#include <time.h>
#include <stdlib.h>
bool    doublon(t_stack* stack, int ipt){
	int i = 0;
	while (i < stack->size) {
		if (stack->stack[i] == ipt)
			return (true);
		i++;
	}
	return (false);
}


void    fill_first_stack(char* av[], t_stack* stack, int ac)
{
	srand(time(NULL));
	//int rdm = rand() % 100;
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

void    free_stack(t_stack* stack1, t_stack* stack2)
{
	free(stack1->stack);
	free(stack2->stack);
}



void    display_stack(t_stack* s1, t_stack* s2)
{
	printf("FIRST | SECOND\n");
	int     i = 0;
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

int             get_pivot(t_stack* s, int size)
{
	int             ret;
	int             i;
	int             tmp;

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

int             get_pivot_index(t_stack* s, int pivot)
{
	int             i;

	i = 0;
	while (i < s->size)
	{
		if (s->stack[i] == pivot)
			return (i);
		i++;
	}
	return (i);
}
/*
 * [321] OK
 * [132]        A       OK
 * [231]        B       OK
 * [213]        C
 * [312]        D       OK
 * [123]        E
 */

/*void  stack3(t_stack* s1, t_stack* s2, int size)
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
  }*/

void    second_algo(t_stack* s1, t_stack* s2)
{
	quicksort(s1, s2, s1->size);
	if (s1->stack[s1->size - 1] > s1->stack[s1->size - 2])
		rotate_a(s1, write);
}

bool    checking_sort(t_stack* s)
{
	int             i;

	if (s->size <= 1)
		return (true);
	i = s->size - 1;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (false);
		i--;
	}
	return (true);
}

void    checking(t_stack* stack1)
{
	if (checking_sort(stack1) == true)
		printf("The stack is sorted\n");
	else
		printf("Error, the stack isn't sorted\n");      
}

int             main(int ac, char* av[])
{
	t_stack         stack1;
	t_stack         stack2;

	if (ac < 2)
		return (0);
	g_step = 0;
	stack1.stack = malloc(sizeof(int) * ac - 1);
	stack1.size = 0;
	stack1.first_lap = true;
	stack2.stack = malloc(sizeof(int) * ac - 1);
	stack2.size = 0; 
	fill_first_stack(av, &stack1, ac);
	if (stack1.size != 1 && checking_sort(&stack1) == false)
		second_algo(&stack1, &stack2);
	//checking(&stack1);
	free_stack(&stack1, &stack2);
	//printf("STEP => %d\n", g_step);
	return (0);
}
