/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:21:14 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 13:07:22 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checknumber(char **str)
{
	int	i;

	i = 1;
	while(str[i])
	{
		if(!ft_atoi(str[i]))
		{
			ft_printf("Wrong type\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	printstack(t_stk *a, t_stk *b)
{
	ft_printf("a : ");
	while (a)
	{
		ft_printf("%d(%d)", a->number, a->index);
		a = a->next;
		if (a)
			ft_printf(" - ");
	}
	ft_printf("\nb : ");
	while (b)
	{
		ft_printf("%d(%d)", b->number, b->index);
		b = b->next;
		if (b)
			ft_printf(" - ");
	}
	ft_printf("\n");
}

t_stk	*args(t_stk *a, t_stk *b, int ac, char **av)
{
	char	**str;
	int			c;
	
	a = 0;
	b = 0;
	c = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if ((!checknumber(str)))
			exit (0);
		a = pushswap(a, str, 0);
		a = findindex(a);
	}
	else
	{
		if (!(checknumber(av)))
			exit (0);
		a =  pushswap(a, av, 1);
		a = findindex(a);
	}	
	while (a)
	{
		c++;
		a = a->next;
	}
	if (a < 7)
		minisorting(a, b);
	else
		radixsorting(a, b);
	return (a);
}

int	stacklen(t_stk *a)
{
	int	i;

	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}