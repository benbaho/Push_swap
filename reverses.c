/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:44:16 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/02 16:56:30 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverser(t_stk **a)
{
	t_stk	*free;

	if(!(*a))
		return ;
	free = *a;
	while(free->next)
		free = free->next;
	free->next = *a;
	(*a)->next = NULL;
}

void rra(t_stk **a)
{
	reverser(a);
	ft_printf("rra\n");
}

void rrb(t_stk **b)
{
	reverser(b);
	ft_printf("rrb\n");
}

void rrr(t_stk **a, t_stk **b)
{
	reverser(a);
	reverser(b);
	ft_printf("rrr\n");
}

void reversen(t_stk **a, t_stk **b, int repeat, char mod)
{
	if (mod == 'a' || mod == 'A')
	{
		while (--repeat)
			reverser(a);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (--repeat)
			reverser(b);
	}
	else if (mod == 'r' || mod == 'R')
	{
		while (--repeat)
			reverser(a);
			reverser(b);
	}
}





