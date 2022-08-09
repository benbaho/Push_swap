/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:46:57 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 20:46:57 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_stk *a)
{
	int	i;
	t_stk	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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

int	checknumber(char **str)
{
	int	i;
    int tmp;

	i = 1;
	while(str[i])
	{	
		if(ft_atoi2(str[i]) > 2147483647 || ft_atoi2(str[i]) < -2147483648)
		{
			exit(ft_printf("Max/Min number\n"));
		}
		i++;
	}
	return (1);
}

int *getindex(t_stk *a)
{
    t_stk   *tmp;
    int     i;
    int     *idx;

    i = 0;
    tmp = a;
    idx = ft_calloc(sizeof(int),stacklen(a) + 1);
    while (tmp)
    {
        idx[i++] = tmp->index;
        tmp = tmp->next;
    }
    return (idx);
}

long long   ft_atoi2(const char *str)
{
	long long int	number;
	int				sign;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0') * sign;
		str++;
	}
	return (number);
}
