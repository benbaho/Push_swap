/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:15:35 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 11:44:58 by bdurmus          ###   ########.fr       */
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

t_stk	*args(t_stk *a, int ac, char **av)
{
	int			number;
	int			c;

	c = 0;
	if (!(ac > 2))
	{
		av = ft_split(av[1], ' ');
		c--;
	}
	while (av[++c])
	{
		if (!arginputcontrol(av[c], &number) || !control(a, number, 1))
			exit (ft_printf("hata"));
		a = node(a, ft_atoi(av[c]));
	}
	return (findindex(a));
}

int	main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;
	int		c;

	a = 0;
	b = 0;
	if (!(ac > 1))
		return (0);
	a = args (a, ac, av);
	c = stacklen(a, 0);
	if (c < 7)
		minisorting(&a, &b);
	else
		radixsorting(&a, &b);
	frees(a);
	frees(b);
}
