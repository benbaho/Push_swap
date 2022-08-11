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

//! bit control
int	b_control(t_stk *a, int swipe)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		if ((tmp->index) >> swipe & 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

//! reverse push
static int	r_push(t_stk **a, t_stk **b, int swipe)
{
	int	i;

	i = stacklen(*b, 0);
	if (!(i))
		return (0);
	while (i--)
	{
		if ((*b)->index >> (swipe) & 1)
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

void	radixsorting(t_stk **a, t_stk **b)
{
	int	size;
	int	i;

	i = 0;
	size = stacklen(*a, 0);
	while (1)
	{
		while (size--)
		{
			if ((*a)->index >> i & 1)
				ra(a);
			else
				pb(a, b);
			if (!isitsorted(*a,*b))
				break ;
		}
		i++;
		if (!isitsorted(*a, *b) || !b_control(*a, size) || !r_push(a, b, size))
			break ;
	}
	while (*b)
		pa(a, b);
}
