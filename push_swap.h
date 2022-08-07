/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:02:34 by bdurmus           #+#    #+#             */
/*   Updated: 2022/08/03 13:07:33 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
args
# include <stddef.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_stk
{
	int				number;
	int				index;
	struct s_stk	*next;
} t_stk;


t_stk	*findindex(t_stk *a);
t_stk	*args(t_stk *a, t_stk *b, int ac, char **av);
t_stk	*pushswap(t_stk *stk, char **av, int c);
int		checknumber(char **str);
int		stacklen(t_stk *a);
int		*prepsort(t_stk *a, int *i);
void	printstack(t_stk *a, t_stk *b);
void	minisorting(t_stk **a, t_stk **b);
void	undersix(t_stk**a, t_stk **b, int len);



void	sa(t_stk **a);
void	sb(t_stk **b);
void	ss(t_stk **a, t_stk **b);

void	pb(t_stk **a, t_stk **b);
void 	pa(t_stk **a, t_stk **b);
void	pn(t_stk **a, t_stk **b, int repeat, char mod);

void	ra(t_stk **a);
void	rb(t_stk **b);
void	rr(t_stk **a, t_stk **b);
void	rotatesn(t_stk **a, t_stk **b, int repeat, char mod);

void	rra(t_stk **a);
void	rrb(t_stk **b);
void	rrr(t_stk **a, t_stk **b);
void	reversen(t_stk **a, t_stk **b, int repeat, char mod);


#endif
