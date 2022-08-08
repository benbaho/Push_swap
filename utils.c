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
	c = stacklen(a);
	if (c < 7)
		minisorting(&a, &b);
	else
		radixsorting(&a, &b);
	return (a);
}

int	stacklen(t_stk *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	triple(t_stk **a)
{
	int	*i;

	i = prepsort(*a, i);

	if (i[0] > i[1] && i[2] > i[1] && i[2] > i[0])
		sa(a);
	else if (i[0] < i[1] && i[2] < i[1] && i[0] > i[2])
		rra(a);
	else if (i[0] > i[2] && i[0] > i[1] && i[2] > i[1])
		ra(a);
	else if (i[0] < i[1] && i[0] < i[2] && i[2] < i[1])
	{
		sa(a);
		ra(a);
	}
	else if (i[0] > i[2] && i[1] > i[2] && i[0] > i[1])
	{
		sa(a);
		rra(a);
	}
}

static int	control(t_stk **a, int number, int mod)
{
	t_stk 	*tmp;
	int		i;

	i = mod;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == number && mod == 0)
			return (i);
		if (tmp->number == number)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void seperate(t_stk **a, t_stk **b, int max, int len)
{
	while (len)
	{
		if ((*a)->index == max)
		{
			pb(a, b);
			max--;
			len--;
			continue;
		}
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if ((stacklen(*a) / 2) < control(a, max, 0))
			rra(a);
		else
			ra(a);
	}
}

void	undersix(t_stk **a, t_stk **b, int len)
{
	int	i;

	seperate(a, b, len - 1, len - 3);
	if (len == 4 || len == 5)
		triple(a);
	else if (len == 6)
	{
		triple(a);
		triple(b);
	}
	i = stacklen(*b);
	while (i--)
	{
		pa(a, b);
		ra(a);
	}
}