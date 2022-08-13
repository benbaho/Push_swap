/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:15:35 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 17:09:53 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	b_control(t_stk *a, int size)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		if ((tmp->index) >> size & 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	r_push(t_stk **a, t_stk **b, int size)
{
	int	len;

	len = stacklen(*b, 0);
	if (!(len))
		return (0);
	while (len--)
	{
		if ((*b)->index >> (size) & 1)
			pa(a, b);
		else
			rb(b);
	}
	return (1);
}

static	int	isitsorted(t_stk *a, t_stk *b)
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

void	radixsorting(t_stk **a, t_stk **b, int size, int len)
{
	while (1)
	{
		len = stacklen(*a, 0);
		while (len--)
		{
			if (((*a)->index) >> size & 1)
				ra(a);
			else
			{
				pb(a, b);
				continue ;
			}
			if (!isitsorted(*a, *b))
				break ;
		}
		size++;
		if (!isitsorted(*a, *b) || !b_control(*a, size) || !r_push(a, b, size))
			break ;
	}
	while (*b)
		pa(a, b);
}
