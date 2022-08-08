/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:53:01 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 10:28:20 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk *sx(t_stk *list)
{
	t_stk	*keep;
	t_stk	*tmp;

	if (list && !(list->next))
		return (list);
	keep = list->next;
	tmp = keep->next;
	keep->next = list;
	list->next = tmp;
	return (keep);
}

void	sa(t_stk **a)
{
	*a = sx(*a);
	ft_printf("sa\n");
}

void 	sb(t_stk **b)
{
	*b = sx(*b);
	ft_printf("sb\n");
}

void	ss(t_stk **a, t_stk **b)
{
	*a = sx(*a);
	*b = sx(*b);
	ft_printf("ss\n");
}



