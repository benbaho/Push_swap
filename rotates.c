/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:51:10 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 10:28:21 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotates(t_stk **x)
{
	t_stk	*travel;
	t_stk	*tmp;

	if (!x)
		return ;
	travel = *x;
	tmp = *x;
	while (travel->next)
		travel = travel->next;
	travel->next = tmp;
	*x = (*x)->next;
	tmp ->next = NULL;
}

void ra(t_stk **a)
{
	rotates(a);
	ft_printf("ra\n");
}

void rb(t_stk **b)
{
	rotates(b);
	ft_printf("rb\n");
}

void rr(t_stk **a, t_stk **b)
{
	rotates(a);
	rotates(b);
	ft_printf("rr\n");
}

void rotatesn(t_stk **a, t_stk **b, int repeat, char mod)
{
	if (mod == 'a' || mod == 'A')
	{
		while (--repeat)
			rotates(a);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (--repeat)
			rotates(b);
	}	
	else if (mod == 'r' || mod == 'R')
	{
		while (--repeat)
			rotates(a);
			rotates(b);
	}
}


	

