/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:51:10 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/02 16:57:32 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotates(t_stk **a)
{
	t_stk *tmp;
	t_stk *free;

	if (!(*a))
		return ;
	tmp = *a;
	free = *a;
	while (free->next)
		free = free->next;
	free->next = tmp;
	*a = (*a)->next;
	tmp->next = NULL;
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


	

