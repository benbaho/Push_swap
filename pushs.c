/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:20:55 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 10:23:29 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	pushs(t_stk **a, t_stk **b)
{
	t_stk	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*tmp).next = *a;
	*a = tmp;
}

void	pb(t_stk **a, t_stk **b)
{
	pushs(b, a);
	ft_printf("pb\n");
}

void	pa(t_stk **a, t_stk **b)
{
	pushs(a, b);
	ft_printf("pa\n");
}
