/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:02:34 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/08 11:24:16 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_stk
{
	int				number;
	int				index;
	struct s_stk	*next;
}	t_stk;

t_stk	*args(t_stk *a, int ac, char **av, int c);
t_stk	*node(t_stk *stk, int c);
t_stk	*findindex(t_stk *a);

int		*prepsort(t_stk *a, int *i);
int		argcontrol(char *input, int *arg);
int		control(t_stk *a, int number, int mod);
int		stacklen(t_stk *a, int i);
int		*getindex(t_stk *a);
int		issorted(t_stk *a, t_stk *b);

void	radixsorting(t_stk **a, t_stk **b, int size, int len);
void	minisorting(t_stk **a, t_stk **b, int len);
void	undersix(t_stk **a, t_stk **b, int len);
void	printstack(t_stk *a, t_stk *b);
void	frees(t_stk	*a);
void	triple(t_stk **a);

void	sa(t_stk **a);
void	sb(t_stk **b);
void	ss(t_stk **a, t_stk **b);

void	pb(t_stk **a, t_stk **b);
void	pa(t_stk **a, t_stk **b);
void	ra(t_stk **a);
void	rb(t_stk **b);
void	rr(t_stk **a, t_stk **b);

void	rra(t_stk **a);
void	rrb(t_stk **b);
void	rrr(t_stk **a, t_stk **b);

#endif
