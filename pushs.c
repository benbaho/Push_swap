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

static void pushs(t_stk **a, t_stk **b)
{
	t_stk	*keep;

	if(!(*b))
		return ;
	
	keep = *a;
	*a = (*a)->next;
	keep->next = *b;
}

void pb(t_stk **a, t_stk **b)
{
	pushs(a, b);
	ft_printf("pb\n");
}

void pa(t_stk **a, t_stk **b)
{
	pushs(b, a);
	ft_printf("pa\n");
}

void pn(t_stk **a, t_stk **b, int repeat, char mod)
{
	if (mod == 'A' || mod == 'a')
	{
		while(--repeat)
			pa(a, b);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (--repeat)
			pb(a, b);
	}
}	
