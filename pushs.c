<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:20:55 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/02 16:55:05 by bdurmus          ###   ########.fr       */
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
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:20:55 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/02 16:55:05 by bdurmus          ###   ########.fr       */
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
>>>>>>> 33c4f9fee81162d96c054773bc686e7a0606196d
