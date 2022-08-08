/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:15:35 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 17:09:53 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int isitsorted(t_stk *a, t_stk *b)
{
    t_stk   *tmp;
    int     index;

    tmp = a;
    index = tmp->index;
    while (tmp)
    {
        if (index > tmp->index)
            return (1);
        tmp = tmp->next;
        index = tmp->index;
    }
    tmp = b;
    index = tmp->index;
    while (tmp)
    {
        if (index < tmp->index)
            return (1);
        tmp = tmp->next;
        index = tmp->index;
    }
    return (0);
}

static int isitsame(t_stk *a, t_stk *b)
{
    t_stk   *tmp;
    int     number;

    tmp = a;
    number = tmp->number;
    tmp = tmp->next;
    while (tmp)
    {
        if (number == tmp->number)
            return (0);
        number = tmp->number;
        tmp = tmp->next;
    }
    return (1);
}

void   radixsorting(t_stk **a, t_stk **b)
{
    int     size;
    int     i;

    i = 0;
    size = stacklen(*a);
    while (1)
    {   
        while (size--)
        {
            if ((*a)->index >> i & 1)
                ra(a);
            else
                pb(a, b);
            if (!isitsorted(*a,*b))
                break;
        }   
        i++;
        if (!isitsorted(*a, *b) || !isitsame(*a, *b))
            break;
    }
}