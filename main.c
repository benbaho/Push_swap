/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:15:35 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 12:56:44 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*node(t_stk *stk, int c)
{
	t_stk	*new;
	t_stk	*tmp;

	new = malloc(sizeof(t_stk));
	if (!new && !stk)
		exit(0);
	new->number = c;
	new->next = NULL;
	new->index = 0;
	if (!stk)
		return (new);
	tmp = stk;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (stk);
}

t_stk	*pushswap(t_stk *stk, char **av, int c)
{
	while (av[c] != NULL)
	{
		stk = node(stk, ft_atoi(av[c]));
			c++;
	}
	return (stk);
}


int	main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;
		
	if (!(ac > 1))
		return (0);
	a = args(a, b, ac ,av);
	
}
