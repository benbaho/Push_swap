/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:48:42 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/14 14:53:34 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	isitsame(t_stk *a, int number)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->number == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	*getindex(t_stk *a)
{
	t_stk	*tmp;
	int		i;
	int		*idx;

	i = 0;
	tmp = a;
	idx = ft_calloc(sizeof(int), stacklen(a, 0) + 1);
	while (tmp)
	{
		idx[i++] = tmp->index;
		tmp = tmp->next;
	}
	return (idx);
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
