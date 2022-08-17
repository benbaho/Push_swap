/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:21:14 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 13:07:22 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisorting(t_stk **a, t_stk **b, int len)
{
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*a)->index == 1)
			sa(a);
	}
	else if (len == 3)
		triple(a);
	else
		undersix(a, b, len);
}

void	triple(t_stk **a)
{
	int	*i;

	i = getindex(*a);
	if (i[0] > i[1] && i[1] < i[2] && i[2] > i[0])
		sa(a);
	else if (i[0] < i[1] && i[0] > i[2] && i[2] < i[1])
		rra(a);
	else if (i[0] > i[1] && i[0] > i[2] && i[2] > i[1])
		ra(a);
	else if (i[0] < i[1] && i[0] < i[2] && i[2] < i[1])
	{
		sa(a);
		ra(a);
	}
	else if (i[0] > i[1] && i[0] > i[2] && i[2] < i[1])
	{
		sa(a);
		rra(a);
	}
	free (i);
}

int	control(t_stk *a, int number, int mod)
{
	t_stk	*tmp;
	int		i;

	i = mod;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == number && mod == 0)
			return (i);
		if (tmp->number == number && mod != 0)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	seperate(t_stk **a, t_stk **b, int max, int len)
{
	while (len)
	{
		if ((*a)->index == max)
		{
			pb(a, b);
			max--;
			len--;
		}
		else if ((stacklen(*a, 0) / 2) < control(*a, max, 0))
			rra(a);
		else
			ra(a);
	}
}

void	undersix(t_stk **a, t_stk **b, int len)
{
	int	i;

	seperate(a, b, len - 1, len - 3);
	if (len == 4 || len == 5)
		triple(a);
	else if (len == 6)
	{
		triple(a);
		triple(b);
	}
	i = stacklen(*b, 0);
	while (i--)
	{
		pa(a, b);
		ra(a);
	}
}
