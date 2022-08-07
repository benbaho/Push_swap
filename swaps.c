<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:53:01 by bdurmus           #+#    #+#             */
/*   Updated: 2022/07/29 11:27:39 by bdurmus          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk *sx(t_stk *list)
{
	if (list && !(list->next))
		return (list);
	t_stk	*keep;
	t_stk	*tmp;

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



=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:53:01 by bdurmus           #+#    #+#             */
/*   Updated: 2022/07/29 11:27:39 by bdurmus          ###   ########.tr       */
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



>>>>>>> 33c4f9fee81162d96c054773bc686e7a0606196d
