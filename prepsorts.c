/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepsorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:15:35 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 12:57:24 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(int *x, int *y)
{
	int	c;

	c = *x;
	*x = *y;
	*y = c;
}

static	void	quicksort(int number[], int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				swap(&number[i], &number[j]);
		}
		swap(&number[pivot], &number[j]);
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}

int	*prepsort(t_stk *a, int *i)
{
	t_stk	*tmp;
	int		index;
	int		c;

	index = stacklen(a, 0);
	i = ft_calloc (sizeof(int), index + 1);
	tmp = a;
	c = 0;     
	while (tmp)
	{
		i[c++] = tmp->number;
		tmp = tmp->next;
	}
	quicksort(i, 0, index - 1);
	return (i);
}

t_stk	*findindex(t_stk *a)
{
	t_stk	*tmp;
	int		*i;
	int		idx;

	idx = 0;
	i = prepsort(a, i);
	tmp = a;
	while (tmp)
	{
		idx = 0;
		while (tmp->number != i[idx])
		{
			idx++;
		}
		tmp->index = idx;
		tmp = tmp->next;
	}
	free (i);
	return (a);
}

int	argcontrol(char *input, int *arg)
{
	if (input[0] == '0' && !input[1])
	{
		*arg = 0;
		return (1);
	}
	if (input[0] == '-' && input[1] == '1' && !input[2])
	{
		*arg = -1;
		return (1);
	}
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	return (*arg);
}

int	issorted(t_stk *a, t_stk *b)
{
	int		index;
	t_stk	*tmp;

	tmp = a;
	index = a->index;
	while (tmp)
	{
		if (index > tmp->index)
			return (1);
		index = tmp->index;
		tmp = tmp->next;
	}
	if (!b)
		return (0);
	tmp = b;
	index = b->index;
	while (tmp)
	{
		if (index < tmp->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}