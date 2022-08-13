/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:46:57 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 20:46:57 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_stk *a, int i)
{
	t_stk	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	printstack(t_stk *a, t_stk *b)
{
	ft_printf("a : ");
	while (a)
	{
		ft_printf("%d(%d)", a->number, a->index);
		a = a->next;
		if (a)
			ft_printf(" - ");
	}
	ft_printf("\nb : ");
	while (b)
	{
		ft_printf("%d(%d)", b->number, b->index);
		b = b->next;
		if (b)
			ft_printf(" - ");
	}
	ft_printf("\n");
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

void	frees(t_stk	*a)
{
	t_stk	*tmp;
	t_stk	*del;

	tmp = a;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free (del);
	}
}
