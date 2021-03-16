#ifndef	QUICKSORT_H
# define QUICKSORT_H

bool	chunkStackisSort(t_stack *s1, int size);
int	chunkPivot(t_stack *s, int size);
void	handleMinCase(t_stack *s1, t_stack *s2);
int	split(t_stack *s1, t_stack *s2, int size);
void	quicksort(t_stack *s1, t_stack *s2, int size);

#endif
