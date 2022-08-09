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

t_stk	*args(t_stk *a, t_stk *b, int ac, char **av)
{
	char	**str;
	int			c;
	
	a = 0;
	b = 0;
	c = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!checknumber(str))
			exit(ft_printf("Same number or sorted"));
		a = pushswap(a, str, 0);
		a = findindex(a);
	}
	else
	{
		if (!(checknumber(av)))
			exit (0);
		a =  pushswap(a, av, 1);
		a = findindex(a);
	}
	c = stacklen(a);
	if (c < 7)
		minisorting(&a, &b);
	else
		radixsorting(&a, &b);
	return (a);
}

static void swap(int *x, int *y)
{
	int c;

	c = *x;
	*x = *y;
	*y = c;
}

static void quicksort(int number[], int first, int last)
{
	int i;
	int j;
	int pivot;

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
	int     c;

	tmp = a;
	index = 0;
	c = 0;
	while (tmp)
	{
		index++;
		tmp = tmp->next;
	}
	i = ft_calloc(sizeof(int), index +  1);
	tmp = a;
	while (tmp)
	{
		i[c] = tmp->number;
		tmp = tmp->next;
		c++;
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
		while(tmp->number != i[idx])
		{
			idx++;
		}
		tmp->index = idx;
		tmp = tmp->next;
	}
	free (i);
	return (a);
}
