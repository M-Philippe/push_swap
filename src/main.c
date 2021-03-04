#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_first_stack(char* av[], int* stack, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		stack[i - 1] = atoi(av[i]);
		i++;
	}
}

void	free_stack(int* first_stack, int* second_stack)
{
	free(first_stack);
	free(second_stack);
}

int		main(int ac, char* av[])
{
	int*	first;
	int*	second;

	if (ac < 2)
		return (0);
	second = NULL;
	first = malloc(sizeof(int) * ac);
	fill_first_stack(av, first, ac);
	int i = 0;
	while (i < ac - 1)
		printf("%d\n", first[i++]);
	free_stack(first, second);
	return (0);
}
