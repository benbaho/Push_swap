/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:44:16 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 10:28:22 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverser(t_stk **x)
{
	t_stk	*travel;
	t_stk	*tmp;
	t_stk	*last;

	travel = *x;
	tmp = *x;
	if (!x || !(travel->next))
		return ;
	while (travel->next)
	{
		last = travel;
		travel = travel->next;
	}
	last->next = 0;
	travel->next = tmp;
	*x = travel;
}

void	rra(t_stk **a)
{
	reverser(a);
	ft_printf("rra\n");
}

void	rrb(t_stk **b)
{
	reverser(b);
	ft_printf("rrb\n");
}

void	rrr(t_stk **a, t_stk **b)
{
	reverser(a);
	reverser(b);
	ft_printf("rrr\n");
}
